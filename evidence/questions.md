# Phase 2 questions (REA only)

Evidence IDs are short forms (`ev_` + 8 hex). Full IDs: `evidence/evidence-index.md`.
All REA calls ran against `target/untangle.exe` (SHA-256 1012c8ee…3de3) with the Ghidra 12.1.4 provider (Windows x64 P0, read-only).

| # | Question | REA tool(s) | Evidence IDs | Answer (short) | Confidence |
|---|---|---|---|---|---|
| 1 | Identity | open_binary, binary_overview, list_strings, read_bytes (PE header), inspect_signature | ev_dc3bb3d4, ev_050a2cb0, ev_773c42d8 | PE32+ x86-64 GUI exe, 7 sections + headers; "Version 20260923.616da16"; linker field 14.0; COFF time 2026-09-23 00:30:28 UTC; Authenticode blob present (26,696 bytes at file offset 0x22600), signer not readable (inspect_signature needs macOS); no debug directory, so no PDB/build ID | high (signer: gap) |
| 2 | Structure | xrefs, read_bytes, batch_decompile, procedure_callers/callees | ev_54a33ea7, ev_474fa8cb, ev_f3e4cc63, ev_f7ad8758, ev_951dd08d, ev_cb816f3e, ev_979e13f3 | Game descriptor table at 0x140017000 points to all game functions in 0x140001080–0x140003f10 (untangle.c asserts). Midend (midend.c) parses IDs, makes seeds, runs new_game. Front end windows.c builds menus and GDI drawing. RNG in random.c is SHA-1 based. | high |
| 3 | Rules | batch_decompile | ev_f7ad8758, ev_571db767, ev_0c928f90, ev_f90d97c3 | Drag points; solved when no two edges (without a shared endpoint) intersect; touching counts as intersecting; completed flag set once | high / medium (touching) |
| 4 | Generator | batch_decompile, procedure_pseudo_code | ev_f7ad8758, ev_571db767, ev_0c928f90, ev_2287f35a, ev_da809602, ev_951dd08d | random_new(seed) → n distinct points on floor(sqrt(3n)) grid → greedy planar edges (degree ≤ 4, nearest first) → shuffle labels until circle layout is tangled → desc | high / medium (greedy loop control flow) |
| 5 | Game ID | procedure_pseudo_code, read_bytes | ev_cb816f3e, ev_f7ad8758, ev_676589e5, ev_de1ec223 | `n:a-b,c-d,...` or `n#seed`; first of ':'/'#' splits | high |
| 6 | Rendering | procedure_assembly, read_bytes, batch_decompile | ev_ca98285d, ev_f7ad8758, ev_0c928f90, ev_f8647744, ev_eaa1643a, ev_9a9f9149, ev_979e13f3 | 11 colours, bg = Windows COLOR_MENU; radius 6 (12 for numbers); text size 18; anim 0.13 s / 0.5 s (solve); flash 0.3 s | high (draw-slot mapping: medium) |
| 7 | Input | batch_decompile | ev_f7ad8758, ev_17c98852 | Press within 12 px of nearest point; drag; release inside grid; snap option; keyboard cursor, select, tab; Undo/Redo menu items | high (key codes→keys: medium) |
| 8 | Runtime | — | — | **Gap: runtime capture of the Windows window: not available in REA 6.3.0** (native UI capture is macOS 14+ only) | — |

## Notes
- The exported bundle (`evidence/bundle-phase2.json`, 72 MB, not in git) also holds 7 records from an earlier, unrelated REA session (analyze_javascript_application / trace_* on the REA source, session 4). They are not used here.
- Ghidra did not define functions at 0x140001290, 0x140002f60, 0x140002fb0, 0x140003840, 0x140003e20, 0x140003e50, 0x140003f10. I read their bytes with `read_bytes` and decoded the short x86-64 sequences by hand (analyst inference from REA bytes; ev_4da3c117, ev_17c98852, ev_cfe54f72, ev_eaa1643a, ev_f90d97c3).
- The square-root helper FUN_140003f30 was checked by transcribing the REA pseudocode literally into JavaScript and tabulating it (scratchpad `isqrt.js`): it returns floor(sqrt(x)) for every tested input.
