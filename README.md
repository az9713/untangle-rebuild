# Untangle, rebuilt from REA evidence only

This repository records one test of [REA](https://github.com/morluto/rea) 6.3.0 (with Ghidra 12.1.4) on Windows 11.
An agent (Claude Code, model Opus 5.5) got the shipped Windows binary `untangle.exe` from Simon Tatham's Portable Puzzle Collection, version 20260923.616da16.
It had no source code. It used REA to analyse the binary, wrote its findings, froze them in a git commit, and rebuilt the game as one web page.
Then it downloaded the source code as an answer key. A separate grader agent marked every finding against the key.

## Result

- **Findings:** 52 of 54 checkable claims are correct (96.3 %). 2 are partly correct, and 0 are wrong. The agent predicted 88 %.
- **Fidelity:** L3. The same game ID gives the same puzzle as the original. The grader checked the code line by line, and a side-by-side run (`receipt/side-by-side.gif`) showed it.
- **Prior knowledge:** the model has probably seen this public source in training. An audit after the test found 10 function and field names in the findings (for example `random_upto`, `interpret_move`) that occur 0 times in REA's output. They came from memory. So 96.3 % is the highest score that REA alone could explain. Receipt section 11 gives the details.

## Live pages

- **Receipt:** https://az9713.github.io/untangle-rebuild/receipt/rebuild-receipt.html
- **Playable rebuild:** https://az9713.github.io/untangle-rebuild/rebuild/index.html

## Where to start

1. Open the receipt (live link above, or `receipt/rebuild-receipt.html`). It contains the prompt, the timeline, all claims with verdicts, the GIF, a playable copy of the rebuild, the tool ledger, the rule audit and section 11, "How the reverse engineering was done".
2. To play the rebuild alone, open the live rebuild link above, or `rebuild/index.html`. Type a game ID such as `10#123456789012345` and select "Load game ID / seed".

## Layout

| Path | Contents |
|---|---|
| `rebuild-prompt.md` | The test prompt, verbatim (paths changed to `<user>`) |
| `target/` | `untangle.exe` (SHA-256 `1012C8EE…3DE3`, 167,496 bytes) and `PROVENANCE.md` |
| `evidence/` | REA outputs, `questions.md`, `evidence-index.md` (evidence IDs), rebuild captures, GIF frames |
| `findings-before-key.md` | Claims C1–C57 and gaps G1–G11, frozen before the key download |
| `findings-addendum.md` | Facts A1–A8, added after the freeze and before the key |
| `rebuild/` | `index.html` (the rebuild) and `selfcheck.js` |
| `key/` | The source release `puzzles-20260923.616da16` (answer key) and `KEY-PROVENANCE.md` |
| `grading.md` | The grader's verdicts, verbatim, and the phase 6 differences |
| `receipt/` | The receipt, its template and the scripts that build it |
| `tool-log.md` | The hand-kept log of each non-REA tool use |

Not in the repository: `evidence/bundle-phase2.json` (the 72 MB REA evidence export; its SHA-256 is in `evidence/bundle-phase2.sha256`) and `key/puzzles.tar.gz` (SHA-256 `CC419C80…B78E`).

## How to check the timeline

The findings were frozen at 22:49:55 −0700. The key was downloaded at 23:01:43 −0700, after that commit.

1. Run `git log --format="%h %ci %s"`. Find the commit "phase 3: findings before key".
2. Run `git diff 3f51ccb HEAD -- findings-before-key.md`. The output must be empty.
3. Compare the SHA-256 of `findings-before-key.md` with `findings-before-key.sha256` (`E2192039…77F6`).

## History rewrite and old commit hashes

On 2026-10-11, before the first push, every commit was rewritten once to remove personal data. Commit times and file contents did not change, except for the removed data. Commit hashes changed. `grading.md`, `findings-addendum.md` and `key/KEY-PROVENANCE.md` still use the old hashes. Use this table to find the new ones.

| Old | New | Commit |
|---|---|---|
| 9eff675 | 19d4b6d | phase 0: setup |
| 7cd33d8 | f5f4f86 | phase 1: binary |
| 627c2b6 | ac734b8 | phase 2: REA analysis |
| fa61c44 | 3f51ccb | phase 3: findings before key |
| 91814f6 | 443a3bf | phase 4: rebuild |
| 609cb2e | e290fc8 | phase 4: rebuild (addendum citations) |
| de11966 | eb4d719 | phase 5: key downloaded |
| 298463f | e02af54 | phase 5: grading |
| c00a13e | 5c1e65a | phase 6: side-by-side GIF |
| 328aed0 | 6135b70 | phase 7: receipt |
| fde4f3e | 03fb5e5 | phase 7: receipt (correction) |
| 9f18f63 | c049fc6 | post-test: receipt section 11 |

Removed data: the Windows login name in file paths (now `<user>`), Claude Code session IDs (now `<session-id>`), and the user's first name in the logs (now "the user"). The commit author e-mail was kept.

## Licences

`target/untangle.exe` and `key/puzzles-20260923.616da16/` are by Simon Tatham and others, under the MIT licence. See `key/puzzles-20260923.616da16/LICENCE`.
