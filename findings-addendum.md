# Findings addendum (after the phase 3 commit)

Facts found or made precise after `findings-before-key.md` was frozen (commit fa61c44, 22:49:55 −0700).
All come from REA evidence that already existed at phase 3 (re-reading the same decompiled output), unless marked.

| Time (−0700) | # | Fact | Evidence | Confidence |
|---|---|---|---|---|
| 2026-10-10 22:55 | A1 | Correction to C52: when no keyboard cursor exists, an arrow key first sets the cursor to point 0 and then searches from point 0 in that direction; the first press can therefore land on another point. | ev_f7ad8758 (0x140002fd0, `if (cursor < 0) cursor = 0`) | high |
| 2026-10-10 22:55 | A2 | Cursor-cone distance = (dx² + dy²) div (pd·cd)² as unsigned integer division, then converted to float; first index wins a tie. | ev_f7ad8758 | high |
| 2026-10-10 22:55 | A3 | Mouse-press distance uses truncated integer screen positions (x·ts div d) minus the mouse position. | ev_f7ad8758 | high |
| 2026-10-10 22:55 | A4 | Animation length with dir < 0 reads the "just solved" flag of the first (old) state argument; with dir ≥ 0 it reads the second (new) state. | ev_eaa1643a (`cmovs rdx, rcx`) | high |
| 2026-10-10 22:55 | A5 | execute_move clears the "just solved" byte (+0x2a) of the new state before parsing; `S` sets both +0x29 (cheated) and +0x2a. | ev_f7ad8758 (0x140003600) | high |
| 2026-10-10 22:55 | A6 | After a keyboard drop the cursor is the dropped point; after a mouse release the cursor is cleared (−1). | ev_f7ad8758 | high |
| 2026-10-10 22:55 | A7 | Return value 0x14001c07a (third empty-string sentinel) is used when a cursor move finds no point; 0x14001c078 = UI update, 0x14001c079 = no effect (pointer identity, all three point to empty strings). | ev_f7ad8758, ev_3949296d | medium |
| 2026-10-10 23:00 | A8 | REA `capture_web_screenshot` and `capture_browser_scenario` (connect mode, CDP 127.0.0.1:9333) work on this Windows laptop. `capture_browser_scenario` has no drag action, so mouse dragging was not tested by REA; keyboard play was. | ev_312169a6, ev_452cfd9e, ev_91e9e682, ev_1cd105cc | high |
