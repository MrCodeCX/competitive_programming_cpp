#!/usr/bin/env python3
import json
import pathlib
import re


def extract_block(text, title):
	lines = text.splitlines()
	start = None
	for i, line in enumerate(lines):
		if line.strip() == f"// {title}:":
			start = i + 1
			break
	if start is None:
		return ""

	headings = {"Problem:", "Link:", "Summary:", "Solve:"}
	block = []
	started = False
	for index in range(start, len(lines)):
		line = lines[index]
		stripped = line.strip()
		if stripped == "":
			next_comment = False
			for next_line in lines[index + 1:]:
				next_stripped = next_line.strip()
				if next_stripped == "":
					continue
				next_comment = next_stripped.startswith("//")
				break
			if next_comment:
				if started:
					block.append("")
				continue
			break
		if not stripped.startswith("//"):
			break

		content = stripped.removeprefix("//")
		if content.startswith(" "):
			content = content[1:]
		content = content.rstrip()

		if content in headings:
			break
		if title == "Summary" and content == "":
			break
		if content == "" and not started:
			continue

		block.append(content)
		started = True

	return "\n".join(block).strip()


def extract_line(text, title):
	match = re.search(rf"// {title}:\s*(.+)", text)
	return match.group(1).strip() if match else ""


def main():
	src_dir = pathlib.Path(__file__).resolve().parent
	root = src_dir.parents[1]
	manifest = src_dir / "solutions.json"

	items = []
	for source in sorted((root / "codeforces").rglob("*.cpp")):
		rel = source.relative_to(root)
		if "known_issues" in rel.parts:
			continue

		text = source.read_text(errors="replace")
		artifact_id = str(rel.with_suffix("")).replace("/", "_")
		items.append({
			"id": artifact_id,
			"source": str(rel),
			"problem": extract_line(text, "Problem"),
			"link": extract_line(text, "Link"),
			"summary": extract_block(text, "Summary"),
			"solve": extract_block(text, "Solve"),
			"js": f"wasm/{artifact_id}.js",
		})

	manifest.write_text(json.dumps(items, indent=2) + "\n")


if __name__ == "__main__":
	main()
