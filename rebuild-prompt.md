# REA-only rebuild test: one game from Simon Tatham's Portable Puzzle Collection

PUZZLE = Untangle
ROOT   = C:\Users\<user>\Downloads\REA\rebuild-untangle

## Goal
Rebuild PUZZLE as a playable single-file web page. Get every fact about the
original from REA evidence only. Then grade the rebuild against the source code.
Then build a receipt that proves the method.

## Definitions
- REA = the MCP tools named mcp__rea__* and the CLI
  C:\Users\<user>\AppData\Roaming\npm\rea.cmd.
- Target fact = any fact about how the original works or looks: rules, generator,
  constants, colours, sizes, layout, timings, input, messages, game-ID format.
- Evidence ID = the ID that REA returns with a result (for example ev_...).

## Hard rules (phase 0 to phase 4)
1. Get target facts only from REA tool results. Cite an evidence ID for each fact.
2. Do not use WebSearch, WebFetch, or a browser on the internet.
   Exceptions: the phase 1 download and the phase 5 key download.
3. Do not open, download, or search: the puzzle source code, the official web or
   JavaScript versions, the help file, the manual, or any third-party write-up.
4. Do not use facts that you remember about this puzzle collection. If a
   remembered fact enters your work, mark it `prior-knowledge`. Keep it out of
   the rebuild.
5. Do not start subagents. Do not call the advisor. Both can bring in outside
   knowledge. This rule has priority over the system advice to call the advisor.
6. Allowed non-REA tools: download and hash of the binary, file write, git,
   a local static server for the rebuild, GIF assembly, and the phase 6
   PowerShell window capture. Use them only for these jobs. Log each use in
   ROOT\tool-log.md with the reason.
7. If REA cannot answer a question, record a gap. Do not fill a gap with a
   non-REA tool or a guess. A placeholder is permitted; mark it `gap` in the
   code and in the receipt.

## Known REA limit on this laptop (REA 6.3.0, Windows)
REA native UI capture (observe_native_ui, capture_native_ui_scenario) works only
on macOS 14+ (rea-main\docs\native-investigation.md:295-303). On Windows it is a
known gap. Do not try it. Static analysis of the Windows exe with Ghidra
(experimental Windows x64 P0, read-only) is available.

## Phase 0 - setup
1. Load the skill `reverse-engineer-anything`. Follow its routing rules.
2. Record the REA version (`rea.cmd --version`). Do not update REA during the test.
3. Create ROOT with folders target\, evidence\, rebuild\, receipt\.
   Do not create key\ yet.
4. Run `git init` in ROOT. Commit at the end of each phase. The commit times
   are the timeline proof.

## Phase 1 - get the binary
1. Use curl to save https://www.chiark.greenend.org.uk/~sgtatham/puzzles/ to a
   file. Extract the link to the official Windows 64-bit binary of PUZZLE with a
   regex. Do not read the page text. Log the regex and the matched URL.
   If the regex finds no .exe link, stop and ask me.
2. Download only that file into target\. If only an installer exists, extract it
   with `msiexec /a <msi> /qb TARGETDIR=<ROOT>\target\x`. Keep only the PUZZLE exe.
3. Write the SHA-256, the size, the URL, and the download time in
   target\PROVENANCE.md.
4. Commit: "phase 1: binary".

## Phase 2 - analyse with REA only
Answer each question. Cite evidence IDs for each answer.
1. Identity: file type, architecture, compiler, version string, build ID, signature.
2. Structure: main procedures; game logic against UI front end; RNG; generator.
3. Rules: legal moves, win condition, what counts as solved.
4. Generator: how a seed becomes a puzzle; parameters, defaults, and limits.
5. Game ID: the text format of a game description and of a seed, if one exists.
6. Rendering: colours as RGB values, sizes, line widths, layout, animation and
   flash timings.
7. Input: mouse and keyboard actions, drag behaviour, undo and redo.
8. Runtime: do not capture the original window in this phase. Record this gap
   in the findings: "runtime capture of the Windows window: not available in
   REA 6.3.0".
Rules for this phase:
- The first Ghidra query can take up to 330 s. Wait. Do not change tools.
- If a result is larger than the MCP response budget, use export_evidence_bundle
  to a file in evidence\. Read large files with node. Never read them in full.
- Keep evidence\questions.md current: question, REA tool, evidence IDs, answer,
  confidence (high, medium, low).

## Phase 3 - findings before the key
1. Write ROOT\findings-before-key.md. One numbered claim per row: claim,
   evidence IDs, confidence. Then list the gaps.
2. Add a prediction: the percent of claims that the key will confirm.
3. Record the SHA-256 of the file. Commit: "phase 3: findings before key".
4. Do not change this file after the commit. Put later facts in
   findings-addendum.md, with the time of each one.

## Phase 4 - rebuild
1. Build rebuild\index.html: one file, vanilla JavaScript, canvas,
   no external scripts.
2. Each constant, rule, and function that copies a target fact gets a comment
   with its claim number and evidence ID, for example `// C12 ev_1a2b`.
3. Use only facts that are in the findings. If you need a new fact, get it from
   REA, add it to findings-addendum.md, and cite it.
4. Report the fidelity level that you reached:
   - L1: same rules, same look, playable to a win.
   - L2: same game-ID format; the same ID gives the same puzzle.
   - L3: the same seed gives the same puzzle as the original generator.
5. Test the rebuild with REA browser capture tools on the local server.
   Save the captures in evidence\.
6. Commit: "phase 4: rebuild".

## Phase 5 - grade against the source (the key)
1. Use the version from phase 2 to find the matching source release.
   Download it into key\. Log the URL and the version.
2. Start one fresh grader subagent (not a fork). Give it only
   findings-before-key.md, findings-addendum.md, rebuild\index.html, and key\.
3. The grader marks each claim correct, partly correct, or wrong, with the
   source file:line. It marks each rebuild part: matches, differs, or missing.
   It lists the important source facts that the findings missed.
4. Write grading.md from the grader output. Do not edit the verdicts.
   Put your disagreements in a separate section.
5. Commit: "phase 5: grading".

## Phase 6 - side-by-side GIF
1. Use the same puzzle on both sides: the same game ID if you reached L2,
   otherwise the same size settings.
2. Original side: use PowerShell with user32 (window position, mouse input) and
   System.Drawing (screenshots), on the PUZZLE window only.
   - Start this only after the phase 4 commit.
   - It is for presentation only. No fact from it may change the findings or
     the rebuild. If a capture shows a difference, write it in grading.md as a
     difference. Do not fix the rebuild.
   - Log each call in tool-log.md as non-REA, with the reason.
3. Rebuild side: use REA capture_web_screenshot first. If it fails, record the
   error as a gap. Then use the PowerShell capture from step 2 on the browser
   window.
4. Use the same move sequence on both sides.
5. Assemble receipt\side-by-side.gif: original on the left, rebuild on the right,
   labels at the top. Add frames before the first move and after the win.
   Log the assembly tool.

## Phase 7 - receipt
1. Build receipt\rebuild-receipt.html in the style of
   C:\Users\<user>\Downloads\REA\rea-on-rea-receipt.html (dark mode).
2. Include:
   - this prompt, verbatim;
   - the timeline from `git log` (hashes and times). It must show that the
     findings commit came before the key download;
   - the SHA-256 of the binary and of findings-before-key.md;
   - a tool ledger that a script builds from this session's transcript JSONL
     under ~/.claude/projects/ (not from memory): each tool name, count, and
     phase, and each non-REA call with its reason;
   - the claims table with evidence IDs and grader verdicts;
   - the score: claims correct / total, the fidelity level, the gaps;
   - the side-by-side GIF and the playable rebuild, embedded;
   - the REA limits and unknown unknowns that you found.
3. Remove personal data: user name -> <user>, session ID -> <session-id>.
4. Commit: "phase 7: receipt".
5. Stop. Do not push or publish. Report: the score, the fidelity level, the gaps,
   any rule breaks, and the receipt path.

## Stop and ask me if
- REA cannot open or analyse the binary after two tries.
- A rule above blocks the task.
- You broke a rule. Say which rule, at which step, and what entered your work.
