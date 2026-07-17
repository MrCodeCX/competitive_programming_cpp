const state = {
	solutions: [],
	sources: {},
	selected: null,
	filter: "all",
	query: ""
};

const els = {
	statTotal: document.getElementById("statTotal"),
	statRunnable: document.getElementById("statRunnable"),
	resultCount: document.getElementById("resultCount"),
	searchInput: document.getElementById("searchInput"),
	divisionFilters: document.getElementById("divisionFilters"),
	solutionList: document.getElementById("solutionList"),
	selectedDivision: document.getElementById("selectedDivision"),
	problemTitle: document.getElementById("problemTitle"),
	problemLink: document.getElementById("problemLink"),
	sourcePath: document.getElementById("sourcePath"),
	roundLabel: document.getElementById("roundLabel"),
	artifactId: document.getElementById("artifactId"),
	summaryText: document.getElementById("summaryText"),
	solveText: document.getElementById("solveText"),
	codeTitle: document.getElementById("codeTitle"),
	codeView: document.getElementById("codeView"),
	copyCode: document.getElementById("copyCode"),
	sourceLink: document.getElementById("sourceLink"),
	runStatus: document.getElementById("runStatus"),
	runSample: document.getElementById("runSample"),
	sampleInput: document.getElementById("sampleInput"),
	expectedOutput: document.getElementById("expectedOutput"),
	actualOutput: document.getElementById("actualOutput"),
	matchBadge: document.getElementById("matchBadge"),
	copyInput: document.getElementById("copyInput")
};

const divisionLabels = {
	div_2: "Div. 2",
	div_3: "Div. 3",
	div_4: "Div. 4",
	global: "Global",
	special: "Special"
};

function divisionOf(solution) {
	return solution.source.split("/")[1] || "other";
}

function roundOf(solution) {
	const parts = solution.source.split("/");
	if (parts[1] === "special") {
		return "Special contest";
	}
	return (parts[2] || "").replaceAll("_", " ");
}

function problemName(solution) {
	return solution.problem.replace(/^Codeforces\s+/, "");
}

function githubUrl(solution) {
	return `https://github.com/MrCodeCX/competitive_programming_cpp/blob/main/${solution.source}`;
}

function normalizeOutput(value) {
	return String(value || "").replace(/\r\n/g, "\n");
}

function filteredSolutions() {
	const tokens = state.query.trim().toLowerCase().split(/\s+/).filter(Boolean);
	return state.solutions.filter((solution) => {
		const divisionMatch = state.filter === "all" || divisionOf(solution) === state.filter;
		const haystack = `${solution.problem} ${solution.source} ${solution.summary} ${solution.solve}`.toLowerCase();
		return divisionMatch && tokens.every((token) => haystack.includes(token));
	});
}

function renderFilters() {
	const counts = state.solutions.reduce((acc, solution) => {
		const division = divisionOf(solution);
		acc[division] = (acc[division] || 0) + 1;
		return acc;
	}, {});

	const filters = [["all", `All ${state.solutions.length}`], ...Object.keys(counts).sort().map((key) => [key, `${divisionLabels[key] || key} ${counts[key]}`])];
	els.divisionFilters.innerHTML = "";

	filters.forEach(([key, label]) => {
		const button = document.createElement("button");
		button.type = "button";
		button.className = `filter-button${state.filter === key ? " is-active" : ""}`;
		button.textContent = label;
		button.addEventListener("click", () => {
			state.filter = key;
			render();
		});
		els.divisionFilters.appendChild(button);
	});
}

function renderList() {
	const solutions = filteredSolutions();
	els.resultCount.textContent = String(solutions.length);
	els.solutionList.innerHTML = "";

	if (!solutions.length) {
		const empty = document.createElement("div");
		empty.className = "solution-item";
		empty.innerHTML = "<strong>No matching solutions</strong><span>Try another search or filter.</span>";
		els.solutionList.appendChild(empty);
		return;
	}

	solutions.forEach((solution) => {
		const item = document.createElement("button");
		item.type = "button";
		item.className = `solution-item${state.selected && state.selected.id === solution.id ? " is-active" : ""}`;
		item.innerHTML = `
			<strong>${problemName(solution)}</strong>
			<span>${divisionLabels[divisionOf(solution)] || divisionOf(solution)} · ${roundOf(solution)} · ${solution.source.split("/").pop()}</span>
		`;
		item.addEventListener("click", () => selectSolution(solution.id));
		els.solutionList.appendChild(item);
	});
}

function renderSelected() {
	const solution = state.selected;
	if (!solution) {
		return;
	}

	const division = divisionOf(solution);
	const source = state.sources[solution.id] || "Source file was not included in the static site dataset.";

	els.selectedDivision.textContent = `${divisionLabels[division] || division} · runnable sample`;
	els.problemTitle.textContent = problemName(solution);
	els.problemLink.href = solution.link;
	els.sourcePath.textContent = solution.source;
	els.roundLabel.textContent = roundOf(solution);
	els.artifactId.textContent = solution.id;
	els.summaryText.textContent = solution.summary;
	els.solveText.textContent = solution.solve;
	els.codeTitle.textContent = solution.source.split("/").pop();
	els.codeView.textContent = source;
	els.sourceLink.href = githubUrl(solution);
	els.sampleInput.textContent = solution.sample.input;
	els.expectedOutput.textContent = solution.sample.output;
	els.actualOutput.textContent = "Run the sample to execute the compiled solution.";
	setRunState("Ready");
	setMatchState("Not run");
}

function render() {
	renderFilters();
	renderList();
	renderSelected();
}

function selectSolution(id) {
	state.selected = state.solutions.find((solution) => solution.id === id) || state.solutions[0];
	renderList();
	renderSelected();
}

function setRunState(text, type = "") {
	els.runStatus.textContent = text;
	els.runStatus.className = `status-pill${type ? ` is-${type}` : ""}`;
}

function setMatchState(text, type = "") {
	els.matchBadge.textContent = text;
	els.matchBadge.className = `match-badge${type ? ` is-${type}` : ""}`;
}

async function runSelectedSample() {
	const solution = state.selected;
	if (!solution) {
		return;
	}

	setRunState("Running", "running");
	setMatchState("Running");
	els.actualOutput.textContent = "";
	els.runSample.disabled = true;

	try {
		let offset = 0;
		const output = [];
		const errors = [];
		const input = solution.sample.input;
		const modulePath = `./src/${solution.js}`;
		const moduleFactory = await import(modulePath);

		await moduleFactory.default({
			stdin() {
				if (offset >= input.length) {
					return null;
				}
				const charCode = input.charCodeAt(offset);
				offset += 1;
				return charCode;
			},
			print(text) {
				output.push(String(text));
			},
			printErr(text) {
				errors.push(String(text));
			}
		});

		const actual = output.join("\n") + (output.length ? "\n" : "");
		const expected = normalizeOutput(solution.sample.output);
		const passed = normalizeOutput(actual) === expected;
		els.actualOutput.textContent = actual || "(no stdout)";
		setRunState(passed ? "Completed" : "Mismatch", passed ? "pass" : "fail");
		setMatchState(passed ? "Match" : "Mismatch", passed ? "pass" : "fail");

		if (errors.length) {
			els.actualOutput.textContent += `\n\nstderr:\n${errors.join("\n")}`;
		}
	}
	catch (error) {
		els.actualOutput.textContent = String(error && error.stack ? error.stack : error);
		setRunState("Failed", "fail");
		setMatchState("Error", "fail");
	}
	finally {
		els.runSample.disabled = false;
	}
}

async function copyText(text, labelElement, label) {
	await navigator.clipboard.writeText(text);
	const previous = labelElement.textContent;
	labelElement.textContent = label;
	window.setTimeout(() => {
		labelElement.textContent = previous;
	}, 1100);
}

async function init() {
	const [solutions, sources] = await Promise.all([
		fetch("src/solutions.json").then((response) => response.json()),
		fetch("data/sources.json").then((response) => response.json())
	]);

	state.solutions = solutions;
	state.sources = sources;
	state.selected = solutions[0];
	els.statTotal.textContent = String(solutions.length);
	els.statRunnable.textContent = String(solutions.filter((solution) => solution.sample && solution.js).length);

	els.searchInput.addEventListener("input", (event) => {
		state.query = event.target.value;
		renderList();
	});

	els.runSample.addEventListener("click", runSelectedSample);
	els.copyCode.addEventListener("click", () => copyText(els.codeView.textContent, els.copyCode, "Copied"));
	els.copyInput.addEventListener("click", () => copyText(els.sampleInput.textContent, els.copyInput, "Copied"));

	render();
}

init().catch((error) => {
	els.problemTitle.textContent = "Unable to load solution data";
	els.summaryText.textContent = "This static site uses fetch() and ES modules. Open it through GitHub Pages or a local static server instead of file://.";
	els.solveText.textContent = String(error && error.stack ? error.stack : error);
	setRunState("Load failed", "fail");
});
