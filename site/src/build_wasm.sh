#!/usr/bin/env bash
set -euo pipefail

src_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
root_dir="$(cd "$src_dir/../.." && pwd)"
wasm_dir="$src_dir/wasm"

mkdir -p "$wasm_dir"

mapfile -t sources < <(find "$root_dir/codeforces" -type f -name '*.cpp' \
	! -path "$root_dir/codeforces/known_issues/*" | sort)

for source in "${sources[@]}"; do
	relative="${source#$root_dir/}"
	id="${relative%.cpp}"
	id="${id//\//_}"
	output="$wasm_dir/$id.js"

	em++ "$source" \
		-std=gnu++17 \
		-O2 \
		-sMODULARIZE=1 \
		-sEXPORT_ES6=1 \
		-sSINGLE_FILE=1 \
		-sENVIRONMENT=web \
		-sALLOW_MEMORY_GROWTH=1 \
		-sFORCE_FILESYSTEM=1 \
		-o "$output"
done

"$src_dir/generate_solutions_json.py"
