#!/usr/bin/env python3
"""Structural checks for the arduino-exercises sketch layout.

Rules (see the top-level README, "Layout"):
  * every top-level directory (except tests/ and .github/) is a sketch
    folder and contains <folder-name>/<folder-name>.ino
  * each sketch defines setup() and loop()
  * each sketch folder has a README.md
  * the top-level README.md exists and is a real README, not the old
    one-line stub

Stdlib only. Exit 0 when everything passes, 1 otherwise.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
IGNORED_DIRS = {"tests", ".github", ".git"}


def find_problem(dirs, ino):
    """Check one sketch folder. Returns a new list of problem strings."""
    found = []
    if not ino.is_file():
        found.append(f"{dirs}/: expected {dirs}/{dirs}.ino")
        return found

    src = ino.read_text(encoding="utf-8", errors="replace")
    if not re.search(r"^\s*void\s+setup\s*\(\s*\)", src, re.M):
        found.append(f"{dirs}: missing void setup()")
    if not re.search(r"^\s*void\s+loop\s*\(\s*\)", src, re.M):
        found.append(f"{dirs}: missing void loop()")

    if not (ROOT / dirs / "README.md").is_file():
        found.append(f"{dirs}/: missing README.md")
    return found


def main():
    problems = []

    readme = ROOT / "README.md"
    if not readme.is_file():
        problems.append("README.md: missing")
    else:
        text = readme.read_text(encoding="utf-8", errors="replace")
        if len(text.strip()) < 200 or "respository" in text:
            problems.append("README.md: still the one-line stub")

    for entry in sorted(ROOT.iterdir()):
        if not entry.is_dir() or entry.name in IGNORED_DIRS:
            continue
        ino = entry / f"{entry.name}.ino"
        if not ino.is_file():
            # A directory that is not a sketch folder — say so explicitly
            # (e.g. a forgotten nested folder from the old layout).
            problems.append(
                f"{entry.name}/: not a sketch folder (no {entry.name}/{entry.name}.ino)"
            )
            continue
        problems += find_problem(entry.name, ino)

    if problems:
        print("validate_sketches: FAILED")
        for p in problems:
            print(f"  - {p}")
        return 1

    sketches = [
        e.name for e in sorted(ROOT.iterdir())
        if e.is_dir() and e.name not in IGNORED_DIRS and (e / f"{e.name}.ino").is_file()
    ]
    print(f"validate_sketches: OK ({len(sketches)} sketches: {', '.join(sketches)})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
