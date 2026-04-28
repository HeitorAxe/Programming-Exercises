#!/usr/bin/env python3
"""Auto-generate README.md for the Programming-Exercises repository."""

import json
import re
import subprocess
import urllib.parse
from collections import defaultdict, Counter
from datetime import datetime
from pathlib import Path
from typing import Optional

REPO_ROOT = Path(__file__).resolve().parent.parent
SCRIPTS_DIR = Path(__file__).resolve().parent
METADATA_FILE = SCRIPTS_DIR / "metadata.json"

PLATFORMS = ["LeetCode", "Codeforces", "Beecrowd", "CSES", "misc"]
UTILITY_FILES = {"graph.cpp", "graph_grid.cpp"}
CODE_EXTENSIONS = {".cpp": "C++", ".py": "Python"}


def relpath(filepath: Path) -> str:
    """URL-encoded relative path for Markdown links."""
    return "/".join(urllib.parse.quote(part) for part in filepath.relative_to(REPO_ROOT).parts)


def rawpath(filepath: Path) -> str:
    """Raw relative path for git log matching (preserves spaces)."""
    return str(filepath.relative_to(REPO_ROOT))


# ---------------------------------------------------------------------------
# Data model
# ---------------------------------------------------------------------------

class Problem:
    def __init__(self, filepath: Path):
        self.filepath = filepath
        self.stem = filepath.stem
        self.language = CODE_EXTENSIONS.get(filepath.suffix.lower(), "Other")
        self.platform = self._platform()
        self.problem_id: Optional[str | int] = None
        self.contest: Optional[str] = None
        self.subgroup: Optional[str] = None
        self._parse()

    def _platform(self) -> str:
        for part in self.filepath.parts:
            if part in PLATFORMS:
                return part
        return "Unknown"

    def _parse(self):
        name = self.stem
        if m := re.fullmatch(r"leet_(\d+)", name):
            self.problem_id = int(m.group(1))
        elif m := re.match(r"CF_(\w+)_([A-Z0-9]+)$", name, re.IGNORECASE):
            self.contest = m.group(1)
            self.problem_id = m.group(2).upper()
        elif m := re.fullmatch(r"bee_(\d+)", name):
            self.problem_id = int(m.group(1))
        if "Fase 0 2024" in str(self.filepath):
            self.subgroup = "Fase 0 2024"


# ---------------------------------------------------------------------------
# Collection
# ---------------------------------------------------------------------------

def collect_problems() -> list[Problem]:
    problems = []
    for path in REPO_ROOT.rglob("*"):
        if not path.is_file():
            continue
        if path.suffix.lower() not in CODE_EXTENSIONS:
            continue
        if any(p.startswith(".") for p in path.relative_to(REPO_ROOT).parts):
            continue
        # Skip the scripts folder itself
        if SCRIPTS_DIR in path.parents:
            continue
        if path.name in UTILITY_FILES:
            continue
        if not any(part in PLATFORMS for part in path.parts):
            continue
        problems.append(Problem(path))
    return problems


# ---------------------------------------------------------------------------
# Metadata
# ---------------------------------------------------------------------------

def load_metadata() -> dict[str, dict]:
    """Load problem metadata (difficulty, tags) from metadata.json."""
    if not METADATA_FILE.exists():
        return {}
    with METADATA_FILE.open(encoding="utf-8") as f:
        return json.load(f)


# ---------------------------------------------------------------------------
# Git activity
# ---------------------------------------------------------------------------

def git_activity() -> dict[str, str]:
    """Map raw relative filepath -> first-commit date (YYYY-MM-DD)."""
    try:
        out = subprocess.check_output(
            ["git", "log", "--diff-filter=A", "--name-only",
             "--pretty=format:%as", "--reverse"],
            cwd=REPO_ROOT, text=True, stderr=subprocess.DEVNULL,
        )
    except subprocess.CalledProcessError:
        return {}
    result: dict[str, str] = {}
    current_date = ""
    for line in out.splitlines():
        line = line.strip()
        if not line:
            continue
        if re.match(r"\d{4}-\d{2}-\d{2}$", line):
            current_date = line
        elif current_date:
            result[line] = current_date
    return result


def monthly_additions(file_dates: dict[str, str], problems: list[Problem]) -> Counter:
    counts: Counter = Counter()
    for p in problems:
        date = file_dates.get(rawpath(p.filepath))
        if date:
            counts[date[:7]] += 1
    return counts


# ---------------------------------------------------------------------------
# Rendering helpers
# ---------------------------------------------------------------------------

def bar(value: int, total: int, width: int = 20) -> str:
    if total == 0:
        return "░" * width
    filled = round(value / total * width)
    return "█" * filled + "░" * (width - filled)


def pct(value: int, total: int) -> str:
    return f"{value / total * 100:.1f}%" if total else "0%"


# ---------------------------------------------------------------------------
# README generation
# ---------------------------------------------------------------------------

def generate(problems: list[Problem], meta: dict, file_dates: dict) -> str:
    now = datetime.now().strftime("%Y-%m-%d %H:%M")
    parts: list[str] = []

    by_platform: dict[str, list[Problem]] = defaultdict(list)
    for p in problems:
        by_platform[p.platform].append(p)

    # LeetCode: group by problem ID (same problem in multiple languages = 1 unique)
    leet_by_id: dict[int, list[Problem]] = defaultdict(list)
    for p in by_platform.get("LeetCode", []):
        if isinstance(p.problem_id, int):
            leet_by_id[p.problem_id].append(p)

    cf_by_contest: dict[str, list[Problem]] = defaultdict(list)
    for p in by_platform.get("Codeforces", []):
        if p.contest:
            cf_by_contest[p.contest].append(p)

    unique_total = (
        len(leet_by_id)
        + len(by_platform.get("Codeforces", []))
        + len(by_platform.get("Beecrowd", []))
        + len(by_platform.get("CSES", []))
    )
    total_files = len(problems)
    lang_count = Counter(p.language for p in problems)

    all_tags: list[str] = []
    leet_diff: Counter = Counter()
    for name, m in meta.items():
        diff = m.get("difficulty")
        if diff in ("EASY", "MEDIUM", "HARD"):
            leet_diff[diff] += 1
        all_tags.extend(m.get("tags", []))
    tag_count = Counter(all_tags)

    monthly = monthly_additions(file_dates, problems)
    active_platforms = [pl for pl in PLATFORMS if pl != "misc" and by_platform.get(pl)]

    # ---- Header ----------------------------------------------------------------
    parts += [
        "# Programming Exercises",
        "",
        f"> Auto-generated on {now}  |  [HeitorAxe](https://github.com/HeitorAxe)",
        "",
        "---",
        "",
    ]

    # ---- Overview --------------------------------------------------------------
    parts += [
        "## Overview",
        "",
        "| Stat | Value |",
        "|------|-------|",
        f"| Unique Problems Solved | **{unique_total}** |",
        f"| Total Solution Files | **{total_files}** |",
        f"| Platforms | **{len(active_platforms)}** ({', '.join(active_platforms)}) |",
        f"| Languages | **{len(lang_count)}** ({', '.join(f'{l}: {c}' for l, c in lang_count.most_common())}) |",
        f"| Multi-language Problems | **{sum(1 for v in leet_by_id.values() if len(v) > 1)}** (LeetCode solved in both C++ and Python) |",
        "",
    ]

    # ---- Platform Breakdown ----------------------------------------------------
    parts += [
        "## By Platform",
        "",
        "| Platform | Unique Problems | Files | C++ | Python | Share |",
        "|----------|----------------|-------|-----|--------|-------|",
    ]
    for pl in active_platforms:
        probs = by_platform[pl]
        unique = len(leet_by_id) if pl == "LeetCode" else len(probs)
        cpp = sum(1 for p in probs if p.language == "C++")
        py = sum(1 for p in probs if p.language == "Python")
        b = bar(unique, unique_total)
        parts.append(f"| {pl} | {unique} | {len(probs)} | {cpp} | {py} | `{b}` {pct(unique, unique_total)} |")
    parts += [""]

    # ---- Language Distribution -------------------------------------------------
    parts += [
        "## Language Distribution",
        "",
        "| Language | Files | Share |",
        "|----------|-------|-------|",
    ]
    for lang, count in lang_count.most_common():
        b = bar(count, total_files)
        parts.append(f"| {lang} | {count} | `{b}` {pct(count, total_files)} |")
    parts += [""]

    # ---- Monthly Activity ------------------------------------------------------
    if monthly:
        parts += [
            "## Monthly Activity",
            "",
            "| Month | Added | Bar |",
            "|-------|-------|-----|",
        ]
        max_month = max(monthly.values())
        for month in sorted(monthly):
            count = monthly[month]
            b = bar(count, max_month, width=15)
            parts.append(f"| {month} | {count} | `{b}` |")
        sorted_months = sorted(monthly.keys())
        parts += [
            "",
            "| Stat | Value |",
            "|------|-------|",
            f"| First active month | **{sorted_months[0]}** |",
            f"| Most recent month | **{sorted_months[-1]}** |",
            f"| Most productive month | **{monthly.most_common(1)[0][0]}** ({monthly.most_common(1)[0][1]} problems) |",
            f"| Active months | **{len(monthly)}** |",
            "",
        ]

    # ---- Tags Overview ---------------------------------------------------------
    if tag_count:
        parts += [
            "## Tags Overview",
            "",
            "| Tag | Count | Bar |",
            "|-----|-------|-----|",
        ]
        max_tag = tag_count.most_common(1)[0][1]
        for tag, count in tag_count.most_common(20):
            b = bar(count, max_tag, width=12)
            parts.append(f"| {tag} | {count} | `{b}` |")
        parts += [""]

    # ===========================================================================
    # Per-platform sections
    # ===========================================================================

    # ---- LeetCode --------------------------------------------------------------
    if leet_by_id:
        leet_ids = sorted(leet_by_id.keys())
        leet_files = by_platform["LeetCode"]
        multilang = sum(1 for v in leet_by_id.values() if len(v) > 1)

        parts += [
            "---", "",
            "## LeetCode", "",
            "| Stat | Value |",
            "|------|-------|",
            f"| Unique Problems | **{len(leet_by_id)}** |",
            f"| Solution Files | **{len(leet_files)}** |",
            f"| C++ only | **{sum(1 for v in leet_by_id.values() if all(p.language == 'C++' for p in v))}** |",
            f"| Python only | **{sum(1 for v in leet_by_id.values() if all(p.language == 'Python' for p in v))}** |",
            f"| Both languages | **{multilang}** |",
            f"| Problem ID range | **#{min(leet_ids)} – #{max(leet_ids)}** |",
            f"| Span coverage | **{pct(len(leet_by_id), max(leet_ids) - min(leet_ids) + 1)}** ({len(leet_by_id)} of {max(leet_ids) - min(leet_ids) + 1}) |",
            "",
        ]

        buckets: Counter = Counter()
        for pid in leet_ids:
            buckets[(pid // 100) * 100] += 1
        max_bucket = max(buckets.values())
        parts += [
            "### Problem ID Distribution", "",
            "| Range | Count | Bar |",
            "|-------|-------|-----|",
        ]
        for bucket in sorted(buckets):
            count = buckets[bucket]
            b = bar(count, max_bucket, width=15)
            parts.append(f"| #{bucket}–#{bucket + 99} | {count} | `{b}` |")
        parts += [""]

        if leet_diff:
            total_diff = sum(leet_diff.values())
            parts += [
                "### Difficulty Distribution", "",
                "| Difficulty | Count | Share | Bar |",
                "|------------|-------|-------|-----|",
            ]
            for diff, emoji in [("EASY", "🟢"), ("MEDIUM", "🟡"), ("HARD", "🔴")]:
                count = leet_diff.get(diff, 0)
                if count:
                    b = bar(count, total_diff)
                    parts.append(f"| {emoji} {diff} | {count} | {pct(count, total_diff)} | `{b}` |")
            parts.append(f"| *(untagged)* | {len(leet_by_id) - total_diff} | {pct(len(leet_by_id) - total_diff, len(leet_by_id))} | |")
            parts += [""]

        leet_tags: list[str] = []
        for pid in leet_ids:
            leet_tags.extend(meta.get(f"leet_{pid:04d}", {}).get("tags", []))
        leet_tag_count = Counter(leet_tags)
        if leet_tag_count:
            parts += ["### Top Tags", "", "| Tag | Count |", "|-----|-------|"]
            for tag, count in leet_tag_count.most_common(15):
                parts.append(f"| {tag} | {count} |")
            parts += [""]

        parts += [
            "### Problem List", "",
            "| # | Problem | Language(s) | Difficulty | Tags |",
            "|---|---------|-------------|------------|------|",
        ]
        for pid in leet_ids:
            probs = leet_by_id[pid]
            langs = " + ".join(sorted({p.language for p in probs}))
            m_data = meta.get(f"leet_{pid:04d}", {})
            diff = m_data.get("difficulty") or ""
            tags = "; ".join(m_data.get("tags", []))
            cpp_probs = [p for p in probs if p.language == "C++"]
            link_prob = cpp_probs[0] if cpp_probs else probs[0]
            rel = relpath(link_prob.filepath)
            parts.append(f"| {pid} | [leet_{pid:04d}]({rel}) | {langs} | {diff} | {tags} |")
        parts += [""]

    # ---- Codeforces ------------------------------------------------------------
    if by_platform.get("Codeforces"):
        cf_probs = by_platform["Codeforces"]
        parts += [
            "---", "",
            "## Codeforces", "",
            "| Stat | Value |",
            "|------|-------|",
            f"| Total Problems | **{len(cf_probs)}** |",
            f"| Unique Contests | **{len(cf_by_contest)}** |",
            f"| Avg Problems per Contest | **{len(cf_probs) / len(cf_by_contest):.1f}** |",
            f"| Max from one contest | **{max(len(v) for v in cf_by_contest.values())}** |",
            "",
        ]

        parts += ["### By Contest", "", "| Contest | Solved | Problems |", "|---------|--------|----------|"]
        for contest in sorted(cf_by_contest, key=lambda x: (len(x), x)):
            probs_in = cf_by_contest[contest]
            letters = sorted({p.problem_id for p in probs_in if p.problem_id})
            parts.append(f"| {contest} | {len(probs_in)} | {', '.join(letters)} |")
        parts += [""]

        solved_per = Counter(len(v) for v in cf_by_contest.values())
        parts += [
            "### Contest Completion Distribution", "",
            "| Problems Solved | Contests |",
            "|----------------|---------|",
        ]
        for n in sorted(solved_per):
            parts.append(f"| {n} | {solved_per[n]} |")
        parts += [""]

        parts += [
            "### Problem List", "",
            "| Problem | Contest | Part | Language |",
            "|---------|---------|------|----------|",
        ]
        for p in sorted(cf_probs, key=lambda x: (x.contest or "", x.problem_id or "")):
            rel = relpath(p.filepath)
            parts.append(f"| [{p.stem}]({rel}) | {p.contest or ''} | {p.problem_id or ''} | {p.language} |")
        parts += [""]

    # ---- CSES ------------------------------------------------------------------
    if by_platform.get("CSES"):
        cses_probs = by_platform["CSES"]
        parts += [
            "---", "",
            f"## CSES  ·  {len(cses_probs)} problem(s)", "",
            "| Problem | Language | Tags |",
            "|---------|----------|------|",
        ]
        for p in sorted(cses_probs, key=lambda x: x.stem):
            tags = "; ".join(meta.get(p.stem, {}).get("tags", []))
            rel = relpath(p.filepath)
            parts.append(f"| [{p.stem}]({rel}) | {p.language} | {tags} |")
        parts += [""]

    # ---- Beecrowd --------------------------------------------------------------
    if by_platform.get("Beecrowd"):
        bee_probs = by_platform["Beecrowd"]
        general = [p for p in bee_probs if p.subgroup is None]
        fase0 = [p for p in bee_probs if p.subgroup == "Fase 0 2024"]

        parts += [
            "---", "",
            "## Beecrowd", "",
            "| Stat | Value |",
            "|------|-------|",
            f"| Total | **{len(bee_probs)}** |",
            f"| General Problems | **{len(general)}** |",
            f"| Fase 0 2024 (Tournament) | **{len(fase0)}** |",
            "",
        ]
        if general:
            parts += ["### General", "", "| # | Problem | Language |", "|---|---------|----------|"]
            for p in sorted(general, key=lambda x: x.problem_id or 0):
                rel = relpath(p.filepath)
                parts.append(f"| {p.problem_id} | [{p.stem}]({rel}) | {p.language} |")
            parts += [""]

        if fase0:
            parts += ["### Fase 0 2024 (Tournament)", "", "| Problem | Language |", "|---------|----------|"]
            for p in sorted(fase0, key=lambda x: x.stem):
                rel = relpath(p.filepath)
                parts.append(f"| [{p.stem}]({rel}) | {p.language} |")
            parts += [""]

    # ---- Footer ----------------------------------------------------------------
    parts += [
        "---",
        "",
        f"*Auto-generated by [`scripts/generate_readme.py`](scripts/generate_readme.py) · {now}*",
        "",
    ]

    return "\n".join(parts)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    print("Scanning repository...")
    problems = collect_problems()
    print(f"  Found {len(problems)} solution files")

    print("Loading metadata...")
    meta = load_metadata()
    print(f"  Loaded {len(meta)} entries from metadata.json")

    print("Reading git history...")
    file_dates = git_activity()
    print(f"  Mapped {len(file_dates)} file additions")

    print("Generating README...")
    readme = generate(problems, meta, file_dates)

    out = REPO_ROOT / "README.md"
    out.write_text(readme, encoding="utf-8")
    print(f"  Written → {out}")

    by_platform: dict[str, int] = defaultdict(int)
    for p in problems:
        by_platform[p.platform] += 1
    print("\nBreakdown:")
    for pl in PLATFORMS:
        if by_platform.get(pl):
            print(f"  {pl}: {by_platform[pl]} files")


if __name__ == "__main__":
    main()
