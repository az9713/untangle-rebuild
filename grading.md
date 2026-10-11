# Grading — Untangle rebuild against the source key

- Key: `key/puzzles-20260923.616da16/` (see `key/KEY-PROVENANCE.md`), downloaded 2026-10-10 23:01:43 −0700, after the findings commit fa61c44 (22:49:55).
- Grader: one fresh subagent (type `reviewer`: Read/Grep/Glob only, not a fork). Inputs given: findings-before-key.md, findings-addendum.md, rebuild/index.html, key/. Nothing else from this session was given to it.
- The section "Grader output" below is the grader's report, unedited. My notes are in the sections after it.

## Summary
| Item | Result |
|---|---|
| Claims C1–C57 | 52 correct, 2 partly correct (C50, C52), 0 wrong, 3 not checkable from source (C1, C3, C4) |
| Score | 52 / 54 checkable = **96.3%** (my prediction: 88%) |
| Addendum A1–A7 | 7 / 7 correct (A8 not checkable) |
| Fidelity | **L3** — static check by the grader: same seed gives the same description; confirmed at run time in phase 6 (see below) |

## Grader output (verbatim)

# Grading report: Untangle reverse-engineering findings and web rebuild, checked against puzzles-20260923.616da16

I changed no files. All line numbers below refer to the key folder.

## Claim verdicts

| # | Verdict | Source file:line | Note |
|---|---|---|---|
| C1 | not checkable | — | File size, SHA-256, PE subsystem and Ghidra counts are binary facts. |
| C2 | correct | puzzles.rc:24-31; cmake/platforms/windows.cmake:86-89; CMakeLists.txt:268-271; puzzles.txt:3434,3461 | The source defines all the version-resource strings. |
| C3 | not checkable | — | Timestamp, linker version and imports are binary facts. |
| C4 | not checkable | — | The debug directory and the signature are binary facts. |
| C5 | correct | CMakeLists.txt:9-14; cmake/platforms/windows.cmake:1 | The core library plus windows.c and printing.c are linked in. |
| C6 | correct | untangle.c:2022-2071; puzzles.h:84 | The third string is "untangle". 64 = PREFERRED_TILESIZE. 512 = SOLVE_ANIMATES (1<<9). The addresses are not checkable. |
| C7 | correct | untangle.c:2022-2063 | The role order agrees with the struct order. free_params, dup_params and free_ui are not named. |
| C8 | correct | midend.c:1787-1968, 531-668, 750-896; windows.c:1656-1753 | |
| C9 | correct | untangle.c:2065; windows.c:1616,1637 | wants_statusbar = false. |
| C10 | correct | random.c:204-222 | seedbuf[40], databuf[20], pos. |
| C11 | correct | random.c:25-95, 153-189 | |
| C12 | correct | random.c:234-264 | |
| C13 | correct | random.c:266-286 | The assert is bits+3 < 32, so b ≤ 28. |
| C14 | correct | misc.c:313-323 | Equivalent form: i = n−1..1, j = random_upto(i+1). |
| C15 | correct | midend.c:574-601 | |
| C16 | correct | untangle.c:180-192 | |
| C17 | correct | untangle.c:139 | |
| C18 | correct | untangle.c:144-166 | |
| C19 | correct | untangle.c:194-210 | |
| C20 | correct | untangle.c:221-233 | The test is n > INT_MAX/3 (715,827,882), which equals n ≥ 715,827,883. |
| C21 | correct | midend.c:1795-1837 | |
| C22 | correct | untangle.c:565-615 | |
| C23 | correct | untangle.c:831-857, 455-467 | |
| C24 | correct | untangle.c:428-453, 630 | squarert is an integer square root. |
| C25 | correct | untangle.c:635-644 | |
| C26 | correct | untangle.c:659-748 | The degree ≥ 4 break, the candidate filter, the (dist, index) sort, the point check and the edge check all agree. |
| C27 | correct | untangle.c:452, 676, 693 | |
| C28 | correct | untangle.c:755-776 | |
| C29 | correct | untangle.c:781-813 | |
| C30 | correct | untangle.c:524-552 | |
| C31 | correct | untangle.c:79-85 | |
| C32 | correct | untangle.c:338-424, 331-334 | |
| C33 | correct | untangle.c:860-884 | |
| C34 | correct | untangle.c:886-891, 950 | |
| C35 | correct | untangle.c:1612-1692 | 'S' is accepted at any position in the loop, not only at the start. |
| C36 | correct | untangle.c:2009-2016 | |
| C37 | correct | untangle.c:1698-1702 | |
| C38 | correct | untangle.c:51, 2055 | |
| C39 | correct | untangle.c:57-70, 1710-1762; windows.c:340-347 | |
| C40 | correct | misc.c:232-271; untangle.c:1722 | game_redraw does not use colour 0. The midend first draw does use it (midend.c:1336). |
| C41 | correct | untangle.c:1890-1955; windows.c:1609 | |
| C42 | correct | untangle.c:1897-1908 | |
| C43 | correct | untangle.c:43-44, 1949-1952 | |
| C44 | correct | untangle.c:1942-1948; puzzles.h:111,114,118 | 1 = FONT_VARIABLE. 0x101 = ALIGN_VCENTRE\|ALIGN_HCENTRE. |
| C45 | correct | untangle.c:1837-1848 | |
| C46 | correct | untangle.c:1930-1939 | |
| C47 | correct | untangle.c:1960-1974, 1240-1246 | Restart does not animate either (midend.c:939-974), but that is midend logic. |
| C48 | correct | untangle.c:53, 1819-1824, 1976-1985 | |
| C49 | correct | untangle.c:47-48, 1320-1370 | |
| C50 | partly correct | untangle.c:1294-1302 | C integer division truncates toward zero, not floor. With a negative drag position, the point snaps into column 0 instead of cancelling. |
| C51 | correct | untangle.c:1380-1400 | |
| C52 | partly correct | untangle.c:1429-1509; puzzles.h:42-45 | Codes, signs and cone are correct. "First press selects point 0" is wrong (1455-1457). |
| C53 | correct | untangle.c:1511-1586 | |
| C54 | correct | untangle.c:1591-1606 | The backend logic is correct. The Windows front end never sends Shift with Tab (windows.c:3085-3097). |
| C55 | correct | untangle.c:1187-1233 | The dialog also holds a midend item, "Keyboard shortcuts without Ctrl" (midend.c:2945-2955). |
| C56 | correct | untangle.c:990-1134 | |
| C57 | correct | windows.c:1633, 1663-1749; untangle.c:2040, 2064 | The two Help items appear only when a help file exists (windows.c:1742). |
| A1 | correct | untangle.c:1455-1459 | |
| A2 | correct | untangle.c:1310-1312, 1498-1503 | The source does signed `long` division. Unsigned division gives the same result for non-negative operands, so the compiler can legally use it. |
| A3 | correct | untangle.c:1331-1335 | |
| A4 | correct | untangle.c:1966 | |
| A5 | correct | untangle.c:1620, 1666-1670 | The byte offsets are not checkable. The behaviour is correct. |
| A6 | correct | untangle.c:1565, 1380-1381 | |
| A7 | correct | misc.c:18-20; untangle.c:1506-1509, 1609 | The order is UI_UPDATE, NO_EFFECT, UNUSED. A cursor move with no target falls through to MOVE_UNUSED. |
| A8 | not checkable | — | Tooling fact. |

## Counts

- **C1–C57:** 52 correct, 2 partly correct (C50, C52), 0 wrong, 3 not checkable (C1, C3, C4).
- **Score:** 52 / 54 = **96.3%**. The author predicted 88%.
- **A1–A7:** 7 correct, 0 partly correct, 0 wrong, 0 not checkable. (A8 is not checkable.)

## Rebuild parts

| Part | Verdict | Source file:line | Note |
|---|---|---|---|
| SHA-1 | matches | random.c:25-198 | |
| random_new | matches | random.c:210-222 | |
| random_bits | matches | random.c:234-264 | |
| random_upto | matches | random.c:266-286 | |
| shuffle | matches | misc.c:313-323 | |
| Grid size | matches | untangle.c:428-453, 630 | floor(sqrt) equals squarert for valid n. |
| Point placement | matches | untangle.c:635-644 | |
| Edge-building greedy loop | matches | untangle.c:659-748 | Sorted arrays give the same order as tree234 plus qsort. |
| Tangling loop | matches | untangle.c:755-776 | |
| Description format and sorting | matches | untangle.c:565-615 | |
| Aux/solution string | matches | untangle.c:786-813 | |
| Description parse in new_game | differs | untangle.c:847-851, 913-927 | "0-1," passes validation. The rebuild's `parseEdges` then adds a `[NaN, NaN]` edge. |
| Game-ID parsing (':' and '#') | differs | midend.c:1795-1837, 2025 | Split logic matches. The rebuild trims whitespace; the original does not. Bare text is always treated as params. |
| validate_params | matches | untangle.c:221-233 | |
| validate_desc | matches | untangle.c:831-857 | |
| Start circle layout | matches | untangle.c:524-552; puzzles.h:13 | PI equals Math.PI. |
| Crossing test | matches | untangle.c:343-424 | Math.imul copies the 32-bit `long` wrap of Win64. BigInt copies the 64-bit dot product. |
| Completion rule | matches | untangle.c:860-892, 950 | |
| Move string parse/execute | matches | untangle.c:1612-1692 | `sscanf` also accepts '+' and spaces. Generated moves never contain them. |
| Solve (8 symmetries) | matches | untangle.c:990-1134 | `Math.fround` copies the C float arithmetic. |
| Colours | differs | untangle.c:1710-1762; windows.c:342, 1605 | The background is a run-time placeholder (240 grey). The C `RGB()` macro truncates 0.5×255 to 127; the rebuild rounds to 128. |
| Draw order and sizes | matches | untangle.c:1890-1957 | Passes 5, 8, 7, 6. Radius 6, outline colour 4. Radius 12 plus 18-px text. |
| Text font and rendering | differs | windows.c:519-528, 544-556, 602-604, 625-627 | The original is bold, VARIABLE_PITCH\|FF_SWISS. The rebuild is not bold and is anti-aliased. GDI also sets the end pixel of each line and draws Ellipse at 2r+1 px. |
| Animation timings | differs | untangle.c:1960-1974; midend.c:939-974, 1088-1090 | Moves, undo, redo and solve match. Restart, and undo or redo of a Restart, animate 0.13 s in the rebuild. The original does not animate them. |
| Flash timings | matches | untangle.c:1819-1824, 1976-1985; midend.c:907-920 | An undo can never flash in the original, because `completed` is copied forward (untangle.c:950). So "forward only" gives the same result. |
| Interpolation (mix) | matches | untangle.c:1788-1797 | The original uses float, the rebuild uses double. This affects only the drawing. |
| Mouse input | matches | untangle.c:1320-1400 | |
| Snap-to-grid | matches | untangle.c:1254-1308 | The rebuild uses `Math.trunc`, which matches the C code. Claim C50 says floor. |
| Keyboard input | differs | midend.c:1255-1258, 1240-1247; windows.c:2936-2962, 3085-3097; untangle.c:1506-1509 | (1) Space is CURSOR_SELECT2, which cycles points; the rebuild uses Space to pick up and drop. (2) Shift+Tab cycles forward on Windows; the rebuild reverses. (3) The original ignores Shift or Ctrl + arrow; the rebuild moves. (4) The original ignores numpad arrows. (5) When a cursor move finds no point, the original does not redraw. |
| Keyboard shortcuts | missing | midend.c:1004-1039 | No u, r, n, q, Ctrl+Z, Ctrl+Y, Ctrl+R, Ctrl+N, Ctrl+S, Ctrl+Q, '*' or '#'. |
| Preferences and defaults | differs | untangle.c:1187-1233; midend.c:242, 2945-2955 | The three Untangle items and their defaults match. "Keyboard shortcuts without Ctrl" (default on) is missing. |
| Presets | matches | untangle.c:144-166 | |
| Custom dialog | matches | untangle.c:194-219 | |
| Tile size and canvas | matches | untangle.c:51, 1698-1702 | Fixed at 64. The original can use less on a small screen (midend.c:405-436). |
| New random seed | differs (by design) | midend.c:186, 574-581 | The form matches: 15 digits, first digit 1–9. The source is Math.random, not the midend SHA-1 RNG. |
| Undo/redo | matches | midend.c:750-896 | |
| Restart | differs | midend.c:939-974 | Restart animates in the rebuild. Its state and history handling match. |
| New-game undo | missing | midend.c:531-551, 762-819 | |

## L3 static check

I compared `newDesc`, `randomNew`, `randomBits`, `randomUpto`, `shuffle` and `cross` line by line with untangle.c:617-829, random.c:210-286, misc.c:313-323 and tree234.c:400-429.

**Judgement:** a seed string that the original receives verbatim gives the same description and the same aux string in the rebuild. I found no difference in the algorithm. The checked points are:
- the grid shuffle
- the (degree, index) vertex order, which tree234 `index234` gives as sorted order
- the candidate sort by (dist², index)
- the point-on-segment check and the edge-crossing check
- the cumulative tangling shuffle and its pair order
- the encoding with the label map and the re-sort
- the aux encoding
- every branch of `cross()`

**How a "#seed" ID reaches random_new:** the midend splits at the first '#' or ':' (midend.c:1795-1819). It decodes the params over `default_params()` (midend.c:1883-1888) and stores the text after '#' unchanged (midend.c:1960-1962). Then it calls `random_new(seedstr, strlen(seedstr))` (midend.c:593) with `curparams`. The midend does not change the seed text. The rebuild does the same for clean input.

Differences that can change the output:
1. **Whitespace.** `loadId` calls `id.trim()` (index.html:453). The original hashes the text verbatim, so "10#123 " gives a different puzzle.
2. **Bare text in the dialogs.** In the Windows dialogs, text with no '#' or ':' is a seed in "Random Seed..." (DEF_SEED) and a description in "Specific..." (DEF_DESC) (midend.c:2025, 1825-1832). The rebuild treats bare text as params and makes a new random seed (index.html:456-458).
3. **Non-ASCII seeds.** The rebuild hashes UTF-8 (TextEncoder). The Windows front end reads the dialog with `GetDlgItemText` (windows.c:1935), which gives ANSI code-page bytes if the build is ANSI. I did not confirm the build mode.
4. **Rounding in `make_circle`.** The result depends on the C runtime `sin`/`cos` against V8 `Math.sin`/`Math.cos` (untangle.c:546-549). A 1-ulp difference changes a coordinate only when `c + r·sin + 0.5` falls exactly on an integer boundary. This is a platform risk, not a code difference.

## Missed facts

1. Enter or Return becomes CURSOR_SELECT. Space becomes CURSOR_SELECT2, which cycles points as Tab does (midend.c:1255-1258; untangle.c:1591-1606).
2. On Windows, Tab arrives through WM_CHAR with no modifier, so Shift+Tab does not reverse the cycle (windows.c:3085-3097). Only arrow keys carry MOD_SHFT or MOD_CTRL (windows.c:2936-2962). Untangle then ignores a modified arrow, because IS_CURSOR_MOVE needs an exact code (puzzles.h:72; midend.c:1240).
3. Numpad arrows (non-extended keys) become MOD_NUM_KEYPAD digits, and Untangle ignores them (windows.c:2940-2962).
4. Midend key shortcuts: n, u, r and q (one-key shortcuts, default on), Ctrl+N new, '*' or Ctrl+Z undo, '#', Ctrl+R, Ctrl+Y or Ctrl+Shift+Z redo, Ctrl+S solve, Ctrl+Q quit (midend.c:242, 1004-1039, 1236-1237).
5. The Preferences dialog ("Untangle preferences") has 4 items. The first is "Keyboard shortcuts without Ctrl" (midend.c:1778, 2945-2955).
6. Restart adds a RESTART move. You can undo it. It does not animate and does not flash (midend.c:939-974, 907-910, 1088-1090).
7. You can undo New Game when the params stay the same (midend.c:531-551, 700-748, 762-819).
8. A game entered as `params:desc` has no aux, so Solve shows "Solution not known for this puzzle" (midend.c:1953-1957; untangle.c:1001-1003). The error appears in an "Unable to solve" message box (windows.c:2705-2710).
9. A "#seed" ID decodes its params over the built-in defaults. A ":desc" ID decodes over the current params (midend.c:1883-1887). An ID "#123" with no params gives n = 0 and the error "Number of points must be at least four".
10. The dialog titles are "Untangle random selection" and "Untangle game selection". The field names are "Game random seed" and "Game ID" (midend.c:1740-1750).
11. On the first draw, the midend fills the whole window with colour 0 (midend.c:1326-1337). Colour 0 marks the dead space when a resize changes the aspect ratio (untangle.c:1714-1722).
12. If ‖bg‖ < 0.2887, `game_mkhighlight` changes the background colour itself (misc.c:263-268).
13. Windows converts a colour by truncation: 0.5 → 127 (windows.c:1605). Lines are 1-px pens (windows.c:1609). Each line also sets its end pixel (windows.c:604). Circles are drawn by `Ellipse(cx−r, cy−r, cx+r+1, cy+r+1)` (windows.c:627).
14. The number font is bold (FW_BOLD), VARIABLE_PITCH|FF_SWISS, with `lfHeight` −18. It is centred by (ascent+descent)/2 and by width/2 (windows.c:519-556).
15. The cursor search skips points that sit exactly on the cursor point. The cone edges are inclusive (untangle.c:1476-1490).
16. When a cursor move finds no point, the code returns MOVE_UNUSED but leaves the cursor at 0, with no redraw (untangle.c:1455-1457, 1506-1509, 1609).
17. A keyboard pick-up does not snap. Snap applies only from the first arrow move (untangle.c:1555-1557, 1544-1546).
18. Tile size: the midend uses the largest size ≤ 64 that fits the screen. The `UNTANGLE_TILESIZE` and `UNTANGLE_DEFAULT` environment variables change the size and the default params (midend.c:165-171, 208, 405-436).
19. Each new game runs a self-test that solves with the aux string (midend.c:630-644).
20. A Shift-click is a middle click and an Alt-click is a right click. Untangle treats all three buttons the same (windows.c:3024-3029).
21. The first flash frame (flashtime = 0) uses the normal background colour (untangle.c:1819-1820).
22. On Win64, `long` is 32 bits. So `normsq` and the `cross` input differences can overflow for large n (untangle.c:345, 1311).

## Gap check

- **G1:** No. This is run-time capture. The source gives the drawing code but no picture.
- **G2:** Partly. The colour is `GetSysColor(COLOR_MENU)` (windows.c:342). The RGB value is a run-time system setting.
- **G3:** Yes. See missed fact 4 (midend.c:242, 1004-1039, 1236-1237). The menu commands use UI_* codes (windows.c:2680-2715).
- **G4:** Yes:
  - Extended arrow keys give 0x209–0x20c (windows.c:2940-2962; puzzles.h:42-45).
  - Enter or Return gives 0x20d. Space gives 0x20e (midend.c:1255-1258).
  - 0x2000 is MOD_SHFT, from VK_SHIFT, on arrow keys only (puzzles.h:61; windows.c:2936).
  - Tab arrives without Shift (windows.c:3085-3097).
- **G5:** Yes. The calls are draw_rect, draw_line, draw_circle, draw_text and draw_update (untangle.c:1891, 1906, 1944, 1946, 1950, 1957). The slot order is in puzzles.h:771-807.
- **G6:** Yes. Type 1 is FONT_VARIABLE (puzzles.h:118). It maps to a bold VARIABLE_PITCH|FF_SWISS font with no face name (windows.c:519-528). 0x101 is ALIGN_VCENTRE|ALIGN_HCENTRE (puzzles.h:111,114). It centres as described in missed fact 14 (windows.c:544-556). The actual face comes from the Windows font mapper at run time.
- **G7:** Partly. The rule is: the largest size ≤ 64 that fits the screen, or the size the user resizes to (midend.c:378-439; windows.c:1625-1626). The exact value is a run-time value, usually 64.
- **G8:** Yes. `index234` returns the element at an index in sorted order (tree234.c:400-429). `add234` does a sorted insert and returns the existing element for a duplicate (tree234.c:382-387; untangle.c:464-466).
- **G9:** No. This is a binary fact.
- **G10:** Yes. Offset 0x1c is `dragtype`. The layout is dragpoint 0, cursorpoint 4, newpoint 8–19, two bools 20–21, anim_length 24, dragtype 28 (untangle.c:1151-1185). The non-EDITOR build only assigns DRAG_MOVE_POINT = 0. Only the EDITOR build sets DRAG_TOGGLE_EDGE (untangle.c:1149, 1358-1362).
- **G11:** Partly. The source allows the static comparison in the L3 section, which finds the same output for clean ASCII seeds. A run-time comparison is still not possible from source.

---

## My disagreements with the grader
None on the verdicts. Two notes:
1. C52 "partly correct": I agree. I found the same error before the key and recorded the correction as A1 (22:55, before the key download); the grader marks A1 correct. The frozen claim stays partly correct.
2. C50 "partly correct": I agree. The claim text says floor; the rebuild code uses truncation (`Math.trunc`), which the grader confirms matches the source.

## Phase 6 differences (presentation run, after the phase 4 commit)
These come from running the original `untangle.exe 10#123456789012345` (PowerShell user32 + System.Drawing) next to the rebuild (REA `capture_web_screenshot`), with the same 10 mouse drags. Per the prompt, none of this changed the findings or the rebuild.

| # | Observation | Kind |
|---|---|---|
| D1 | Frame 0: the original and the rebuild show the same graph (17 edges) from seed `123456789012345`, point for point. The 10 drags to the rebuild's aux solution also solve the original. This is a run-time confirmation of **L3** for this seed. | match |
| D2 | Background: the original's colour 1 at run time is RGB (240, 240, 240). The rebuild's placeholder (gap G2) is 0.941 × 255 → 240. Same value, but still a guess in the rebuild. | match (by luck of the placeholder) |
| D3 | Tile size at run time: the original client area is 400 × 400 device px for w = 5, so 80 px per grid unit at 125 % display scaling (64 × 1.25). The rebuild canvas is 320 CSS px = 400 device px. Same size on screen. | match |
| D4 | Lines: the original draws hard 1-px black GDI lines; the rebuild's canvas lines are anti-aliased and look grey. | differs |
| D5 | Window frame: the original shows the Windows window frame (rounded bottom corners) and a menu bar; the rebuild is a canvas inside a web page with HTML buttons. | differs |
| D6 | Point circles look the same size (radius 6 × 1.25). The original's GDI ellipse edge is not anti-aliased. | differs (rendering only) |
