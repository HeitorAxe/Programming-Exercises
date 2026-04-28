# scripts/

Tools for maintaining this repository.

---

## generate_readme.py

Scans the repo, reads `metadata.json`, queries git history, and writes a fresh `README.md` at the repo root.

### Usage

Run from anywhere inside the repo:

```bash
python3 scripts/generate_readme.py
```

No dependencies beyond the Python standard library (3.10+).

### How it works

1. Walks every platform folder (`LeetCode/`, `Codeforces/`, etc.) and collects `.cpp` / `.py` files.
2. Parses file names using the naming conventions below to extract platform, problem ID, and language.
3. Reads `scripts/metadata.json` for difficulty and tags.
4. Reads `git log` to build monthly activity stats.
5. Writes `README.md`.

---

## metadata.json

Stores difficulty and tags that cannot be inferred from file names alone.
Edit this file to annotate a problem. The script reads it on every run.

```json
{
  "leet_0330": { "difficulty": "HARD", "tags": ["Greedy", "Sorting"] },
  "CF_189_A":  {                        "tags": ["Dynamic Programming"] },
  "GridPaths": {                        "tags": ["Backtracking"] }
}
```

Keys must exactly match the file stem (no extension). Valid difficulty values: `"EASY"`, `"MEDIUM"`, `"HARD"`.

---

## Naming conventions

The script depends entirely on file names to detect problems. Follow these rules or a file will be silently ignored.

### LeetCode

| Pattern | Example | Notes |
|---------|---------|-------|
| `leet_XXXX.cpp` | `leet_0394.cpp` | C++ solution |
| `leet_XXXX.py` | `leet_0394.py` | Python solution |

- `XXXX` is the zero-padded 4-digit problem number.
- Place C++ files directly in `LeetCode/`.
- Place Python files in `LeetCode/python/`.
- Both files for the same problem are deduplicated — they count as one unique problem.

### Codeforces

| Pattern | Example | Notes |
|---------|---------|-------|
| `CF_NNNN_X.cpp` | `CF_1980_B.cpp` | `NNNN` = contest number, `X` = problem letter |

- The contest number can be any length (`CF_006_B`, `CF_1980_C`).
- The problem part is a single uppercase letter or digit.
- Place files in `Codeforces/`.

### Beecrowd

| Pattern | Example | Notes |
|---------|---------|-------|
| `bee_NNNN.cpp` | `bee_1032.cpp` | General problems |
| `X.cpp` | `a.cpp`, `b.cpp` | Tournament problems (Fase 0 subfolder) |

- General problems go in `Beecrowd/`.
- Tournament problems go in `Beecrowd/Fase 0 2024/` (single-letter filenames are accepted there).

### CSES

| Pattern | Example | Notes |
|---------|---------|-------|
| `ProblemName.cpp` | `GridPaths.cpp` | Descriptive name, no prefix |

- Place files in `CSES/`.
- The stem is used as the problem name in the README, so keep it readable.

### misc

Files in `misc/` are excluded from all stats. Use it for templates and utilities (e.g. `graph.cpp`).

---

## Adding a new platform

1. Create a top-level folder (e.g. `AtCoder/`).
2. Add its name to the `PLATFORMS` list near the top of `generate_readme.py`.
3. Add a parsing branch in `Problem._parse()` and a rendering section in `generate()`.
4. Run the script to verify.
