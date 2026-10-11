# Findings before the key — Untangle (untangle.exe, Windows x64)

Written 2026-10-10, phase 3, before any source download. Every claim comes from REA 6.3.0 tool results
(Ghidra 12.1.4 provider). Short evidence IDs (`ev_` + 8 hex) map to full IDs in `evidence/evidence-index.md`.
"Analyst decode" means I decoded REA-returned bytes or pseudocode myself; the decode is an inference.
Addresses are virtual addresses in the image (base 0x140000000).

## A. Identity

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C1 | The file is a PE32+ x86-64 Windows GUI executable (subsystem 2), 167,496 bytes, SHA-256 1012c8ee95cef698a442227caa2f54caaa48c37d94392b736e772a17b2163de3. Ghidra sees 457 procedures and 469 strings. | open_binary result, ev_dc3bb3d4, ev_773c42d8 | high |
| C2 | Version string "Version 20260923.616da16" (in .data and in FileVersion/ProductVersion). FileDescription "Planar graph layout puzzle"; CompanyName "Simon Tatham"; ProductName "Portable Puzzle Collection"; LegalCopyright "Copyright © 2004-2024 Simon Tatham"; InternalName/OriginalFilename "untangle". | ev_050a2cb0 | high |
| C3 | COFF timestamp 2026-09-23 00:30:28 UTC; optional-header linker version field 14.0. Imports VCRUNTIME140.dll and api-ms-win-crt-* (Universal CRT), so the toolchain is MSVC-compatible; the exact compiler is not identified. | ev_773c42d8 (analyst decode), ev_050a2cb0 | medium |
| C4 | No debug directory, so no PDB path or build ID. An Authenticode signature blob exists (security directory: file offset 0x22600, 26,696 bytes, at the end of the file). Signer and validity are unknown: REA `inspect_signature` needs macOS. | ev_773c42d8 (analyst decode) | high (presence) |
| C5 | Assert paths name the sources linked in: /puzzles/windows.c, random.c, drawing.c, printing.c, untangle.c, midend.c, misc.c, tree234.c. | ev_050a2cb0 | high |

## B. Structure

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C6 | A game descriptor table at 0x140017000 starts with pointers to "Untangle", "games.untangle" and a third string, then holds function pointers 0x140001080…0x140003f10 and data (64 at 0x140017120; 512 at 0x1400171a0). | ev_54a33ea7, ev_f3e4cc63 | high |
| C7 | Roles of the game functions (from what each body does): 0x140001080 default params; 0x1400010a0 preset list; 0x140001130 decode params; 0x140001150 encode params; 0x1400011e0 config dialog; 0x140001260 params from config; 0x140001290 validate params; 0x1400012c0 generator (new description); 0x140002340 validate description; 0x140002450 new game state; 0x1400027e0 duplicate state; 0x1400028a0 free state; 0x140002920 solve; 0x140002ea0 preference list; 0x140002f60 set preferences; 0x140002f80 new UI; 0x140002fb0 changed state; 0x140002fd0 interpret move; 0x140003600 execute move; 0x140003810 compute size; 0x140003840 set size; 0x140003850 colours; 0x1400038e0 / 0x140003980 new/free draw state; 0x1400039b0 redraw; 0x140003e20 animation length; 0x140003e50 flash length; 0x140003e80 cursor location; 0x140003f10 status. | ev_f7ad8758, ev_4da3c117, ev_17c98852, ev_cfe54f72, ev_eaa1643a, ev_f90d97c3 | medium (roles are inferred from behaviour) |
| C8 | Game logic (untangle.c) is separate from the midend (midend.c: game-ID parsing, seed creation, undo states) and the Win32 front end (windows.c: menus, GDI pens/brushes, BitBlt). | ev_474fa8cb, ev_cb816f3e, ev_951dd08d, ev_979e13f3 | high |
| C9 | The window has no status bar: the front end creates one only if game-descriptor byte +0x190 is set, and that byte is 0. | ev_3c2d1045, ev_979e13f3, ev_f3e4cc63 | high |

## C. Random number generator

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C10 | random_new(seed, len) (0x140015140): state = 64 bytes. bytes 0–19 = SHA-1(seed); bytes 20–39 = SHA-1(bytes 0–19); bytes 40–59 = SHA-1(bytes 0–39); position (offset 0x3c) = 0. | ev_da809602 | high |
| C11 | The hash is standard SHA-1: initial values 67452301 efcdab89 98badcfe 10325476 c3d2e1f0, round constants 5a827999 6ed9eba1 8f1bbcdc ca62c1d6, rotate-left-1 message expansion, 0x80 padding and big-endian 64-bit bit length. | ev_da809602, ev_2287f35a | high (identification is an inference from the constants) |
| C12 | random_bits(state, bits) (0x140015270): for each 8 bits needed, take the next output byte, most significant first. When position reaches 20: increment bytes 0–19 as a little-endian counter (carry upward), recompute bytes 40–59 = SHA-1(bytes 0–39), position = 0. Mask the result to `bits` bits. | ev_2287f35a | high |
| C13 | random_upto(state, limit) (0x140015630): b = bit length of limit (assert b ≤ 28); divisor = (8 << b) / limit; repeat v = random_bits(b + 3) until v < divisor × limit; return v / divisor. | ev_0c928f90 | high |
| C14 | shuffle(array, n) (0x140005430): for i = n down to 2: j = random_upto(i); swap elements i−1 and j. | ev_571db767 | high |
| C15 | A new random game gets a 15-digit decimal seed from the midend RNG: first digit '1' + random_upto(9), then 14 digits '0' + random_upto(10). The puzzle RNG is random_new(seed text, strlen). The generator gets the current params and this RNG. | ev_951dd08d | high |

## D. Parameters and game ID

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C16 | Params are one integer n = number of points. Encoded with "%d", decoded with atoi. | ev_f7ad8758, ev_676589e5 | high |
| C17 | Default n = 10. | ev_f7ad8758 | high |
| C18 | Presets (Type menu): 6, 10, 15, 20, 25 points, named "%d points". | ev_f7ad8758, ev_f3e4cc63 | high |
| C19 | Custom dialog: one text field "Number of points". | ev_f7ad8758 | high |
| C20 | validate_params: n < 4 → "Number of points must be at least four"; n ≥ 715,827,883 (0x2aaaaaab) → "Number of points must not be unreasonably large". | ev_4da3c117 (analyst decode) | high |
| C21 | Game ID = `params:desc` or `params#seed`. The first of ':' and '#' splits the string. A seed ID makes the midend generate the description from the seed. | ev_cb816f3e | high |
| C22 | Description = comma-separated edges `a-b`, a < b, vertex numbers 0…n−1, sorted ascending by (a, b). Example form: `10:0-3,0-5,1-2,…`. | ev_f7ad8758, ev_676589e5, ev_de1ec223, ev_80d25da6 | high |
| C23 | validate_desc errors: "Number out of range in game description" (number < 0 or ≥ n), "Expected '-' after number in game description", "Expected ',' after number in game description", "Node linked to itself in game description". An empty description passes. Duplicate edges are not rejected (the edge set ignores duplicates). | ev_f7ad8758 | high |

## E. Generator (0x1400012c0)

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C24 | Grid size w = h = floor(sqrt(3n)) (0x140003f30 is an integer square root; the REA pseudocode, transcribed literally to JavaScript, gives floor(sqrt) for all tested inputs, e.g. n=10 → 5, n=25 → 8). | ev_571db767, evidence/isqrt-transcription.js | high |
| C25 | Point placement: array 0…w²−1 is shuffled (C14); point i takes value v = a[i], x = v mod w, y = v div w (integer grid, denominator 1). | ev_f7ad8758 | high |
| C26 | Edge building: vertices are kept in an ordered tree sorted by (degree, index). Scan positions i = 0…n−1; stop when the vertex at position i has degree > 3. For vertex v at position i, candidates are vertices at later positions with degree < 4 and no edge to v yet, sorted by (squared distance to v, index). Accept the first candidate u such that (1) no other point lies on segment u–v and (2) segment u–v crosses no existing edge that shares no endpoint with it. Add edge (min, max), raise both degrees, restart the scan at position 0. When no candidate is accepted for v, go to position i+1. Finish when a scan adds nothing. | ev_f7ad8758 | medium (complex decompiled control flow; tree234 semantics assumed) |
| C27 | Maximum vertex degree is 4. | ev_f7ad8758 | high |
| C28 | Tangling: a label permutation (start: identity) is shuffled again and again (cumulative) until the circle layout (C30) under that permutation has at least one crossing between two edges that share no endpoint. Edges are checked in edge-tree order. | ev_f7ad8758 | high |
| C29 | Output: each edge (a, b) becomes (min(p[a], p[b]), max(...)); the list is sorted and printed as C22. Aux (solution) = "S" followed by ";P%d:%ld,%ld/%ld" for labels 0…n−1, with the original grid point of each label as (2x+1, 2y+1)/2 (cell centres). | ev_f7ad8758, ev_676589e5 | high |

## F. State, rules and moves

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C30 | Start layout (new_game 0x140002450): point i at angle a = 2πi/n; x = (int)(sin a · r + 32w + 0.5), y = (int)(−cos a · r + 32w + 0.5), denominator 64, r = (192w) div 7. So the points sit on a circle of radius 3w/7 grid units round the grid centre, point 0 at the top, numbers going clockwise. | ev_f7ad8758 | high |
| C31 | Coordinates are rationals x/d, y/d in grid units (each point stores x, y, d). | ev_f7ad8758 | high |
| C32 | Crossing test (0x140004170): exact integer arithmetic with 64-bit products (0x1400043d0 returns a·b + c·d as 64 bits). It is a closed-segment test: a touch or a collinear overlap counts as a crossing; collinear segments that do not overlap do not cross. | ev_571db767, ev_0c928f90 (analyst decode) | medium |
| C33 | Only edge pairs with no shared endpoint are tested. Each edge gets a "crosses" flag. | ev_571db767 | high |
| C34 | Win condition: the state becomes completed when no tested pair crosses. The completed flag is only ever set (never cleared) and is copied to later states. A puzzle with no edges is completed at once. | ev_571db767, ev_f7ad8758 | high |
| C35 | Move string `P<i>:<x>,<y>/<d>` places point i at (x/d, y/d); several moves can be joined by ';'. A leading `S` marks a solve move and sets the cheated flag. A move is rejected if i is out of range or d < 1. | ev_f7ad8758 | high |
| C36 | The game status is the completed flag (1 = solved). | ev_f90d97c3 (analyst decode) | high |

## G. Rendering

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C37 | Canvas = (w × tilesize) square; no border. | ev_f7ad8758 (0x140003810) | high |
| C38 | Preferred tile size = 64 (descriptor value at 0x140017120). | ev_f3e4cc63 | medium (role inferred from position) |
| C39 | 11 colours (r, g, b in 0–1): 0 = lowlight of background; 1 = background = Windows system colour COLOR_MENU (GetSysColor(4)); 2 = black (edge); 3 = red (crossed edge); 4 = black (point outline); 5 = blue (point); 6 = white (dragged point); 7 = grey 0.5 (keyboard cursor point); 8 = red (neighbour of dragged point); 9 = grey 0.5 and 10 = white (completion flash). | ev_f7ad8758, ev_0c928f90 | high |
| C40 | Lowlight colour 0 = bg × (1 − 0.28867513/‖bg‖) when ‖bg‖ ≥ 0.28867513. The redraw does not use colour 0. | ev_0c928f90, ev_ca98285d | high |
| C41 | Redraw: fill whole canvas with the background colour; draw every edge in edge-tree order as a 1-px line; then draw points in four passes by colour 5, 8, 7, 6 (blue first, dragged white last). | ev_ca98285d, ev_f3e4cc63, ev_979e13f3 | high |
| C42 | Edge colour = 3 (red) if the show-crossed-edges preference is on and the edge's crosses flag is set, else 2 (black). During an animation the flags come from the old state. | ev_ca98285d | high |
| C43 | Point (Circles style): circle radius 6 px, fill = point colour, outline = colour 4 (black). | ev_ca98285d | high (draw-slot mapping medium) |
| C44 | Point (Numbers style): circle radius 12 px with fill and outline = current background colour, then the point index as text, font type 1, size 18, alignment flags 0x101, colour = point colour. | ev_ca98285d | medium (meaning of type 1 and 0x101 not analysed) |
| C45 | Screen position = (x · tilesize) div d, (y · tilesize) div d. A dragged point is drawn at the UI drag position. | ev_ca98285d | high |
| C46 | Point colour rules: dragged point → 6; else keyboard cursor point → 7; else neighbour of the dragged point → 8; else 5. | ev_ca98285d | high |
| C47 | Animation length: 0 if the move came from a drag or keyboard drop; 0.5 s for a solve move; 0.13 s for other moves (undo/redo). Positions are interpolated linearly. | ev_eaa1643a, ev_f8647744, ev_17c98852, ev_ca98285d | high |
| C48 | Completion flash: 0.3 s, only when the old state is not completed, the new state is completed, and neither state is cheated. Background colour = 9 + ((int)(t · 4 / 0.3) & 1), so grey/white alternate every 0.075 s. | ev_eaa1643a, ev_f8647744, ev_ca98285d | high |

## H. Input

| # | Claim | Evidence | Confidence |
|---|---|---|---|
| C49 | Mouse press (any of 3 buttons): pick the point nearest to the mouse in screen pixels (first index wins a tie). If its squared distance > 144 (12 px), nothing happens. | ev_f7ad8758 | high |
| C50 | Drag: the point follows the mouse. With snap-to-grid on, x snaps to (2·floor(mx·(n−1) / (ts·w)) + 1)·w / (2n−2) grid units (cell centres of an (n−1) × (n−1) grid over the canvas); y the same. | ev_f7ad8758 | high |
| C51 | Release: if the drop position is inside [0, w) × [0, h) grid units, emit a move; else cancel (the point goes back). | ev_f7ad8758 | high |
| C52 | Cursor keys (codes 0x209–0x20c) with nothing held: move the keyboard cursor to the nearest point inside a 90° cone in that direction (first press selects point 0). Signs: 0x209 −y, 0x20a +y, 0x20b −x, 0x20c +x. | ev_f7ad8758 | high (key names: medium) |
| C53 | Select (0x20d) picks up the cursor point; arrows then move it by tilesize/2 px (snap applies); select again drops it (a move, if inside). | ev_f7ad8758 | high |
| C54 | Tab (9) or select-2 (0x20e) moves the cursor to the next point index (wraps); modifier bit 0x2000 goes backwards. Ignored while a point is held. | ev_f7ad8758 | high |
| C55 | Preferences: "Snap points to a grid" (snap-to-grid, default off), "Show edges that cross another edge" (show-crossed-edges, default off), "Display style for vertices" Circles/Numbers (vertex-style, default Circles). | ev_f7ad8758, ev_17c98852 | high |
| C56 | Solve: needs the aux string (else "Solution not known for this puzzle"). It tries the 8 axis symmetries of the solution round the grid centre, keeps the one with the least squared distance to the current layout (first wins a tie), and emits `S;P…` with coordinates (int)(2t + 0.5)/2. | ev_f7ad8758 | high |
| C57 | Menus: Game = New, Restart, Specific…, Random Seed…, Load…, Save…, Undo, Redo, Solve, Preferences, Exit; Type = presets + Custom…; Help = About, Contents, Help on Untangle. No Copy item; no Print item (descriptor flags). Window title = "Untangle". | ev_979e13f3, ev_f3e4cc63 | high |

## Gaps (not answered by REA in this run)

| # | Gap | Effect on the rebuild |
|---|---|---|
| G1 | Runtime capture of the Windows window: not available in REA 6.3.0 (native UI capture is macOS 14+ only). | No REA picture of the original. |
| G2 | The RGB value of COLOR_MENU on the target machine (runtime system colour). | Placeholder background, marked `gap`. |
| G3 | Midend keyboard shortcuts (undo, redo, new, quit) were not analysed. | Rebuild uses buttons only. |
| G4 | Windows key → code mapping (which physical key gives 0x209…0x20d, and which modifier is 0x2000). | Arrow/Enter/Space/Shift mapping in the rebuild is inferred, marked `gap`. |
| G5 | Draw-API slot mapping (text/rect/line/circle/update) is inferred from argument shapes; drawing.c was not decompiled. | — |
| G6 | Font face for type 1 and meaning of alignment 0x101. | Rebuild uses centred sans-serif, marked `gap`. |
| G7 | Real tile size chosen at run time by the midend/front end (window sizing). | Rebuild uses 64. |
| G8 | tree234 behaviour assumed (sorted 2-3-4 tree with index/add/find/delete). Not decompiled. | L3 depends on it. |
| G9 | Authenticode signer and validity. | — |
| G10 | UI field at offset 0x1c (checked in drag/release) is never set non-zero in interpret_move; its purpose is unknown. | Ignored. |
| G11 | L3 (same seed → same puzzle) cannot be checked against the original in phase 4 (no runtime). | L3 is implemented but unverified before the key. |

## Prediction
I predict the key will confirm **88%** of the 57 claims as correct (about 50 of 57). The weakest claims are C7 (function roles),
C26 (greedy loop), C32 (touching counts as crossing), C38 (tile size 64) and C44 (text meaning).

## Accidental exposure (rule 6 incident)
During phase 1 a PowerShell variable clash printed about 1 KB of the raw exe bytes (PE header, section names) in an error
message. No claim above uses that output; C1–C4 come from REA calls.
