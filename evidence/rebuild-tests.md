# Phase 4 tests of rebuild/index.html

Server: node static server on 127.0.0.1:8765 (scratchpad `serve.js`). Browser: Chrome with an isolated profile and CDP on 127.0.0.1:9333.

| Test | Tool | Evidence | Result |
|---|---|---|---|
| Logic self-check: SHA-1("abc"), determinism for 5 seeds, desc validates, start layout tangled, max degree 4, Solve gives a solved layout, validate_desc errors, crossing cases | `node rebuild/selfcheck.js` (non-REA, runs our own code only) | console output | pass |
| Page renders seed `10#123456789012345` | REA capture_web_screenshot | ev_312169a6, rebuild-capture-1-start.png | pass |
| Playable to a win by keyboard only: `4:0-2,1-3`, Tab×3, Enter, ArrowUp×5, ArrowRight×2, Enter | REA capture_browser_scenario | ev_452cfd9e, rebuild-capture-2-keyboard-win-0.png (DOM shows "Solved.") | pass |
| Numbers style + show crossed edges | REA capture_browser_scenario | ev_91e9e682, rebuild-capture-3-numbers-crossed-0.png | pass |
| Solve on `10#123456789012345` | REA capture_browser_scenario | ev_1cd105cc, rebuild-capture-4-solve-0.png | pass |
| Mouse drag | — | — | not testable with REA actions (no drag action); gap |

Screenshots are at 125% device scale (Windows display scaling), so the 320-px canvas shows as 400 px.

## Fidelity reached (before the key)
- **L1** (same rules, same look, playable to a win): reached, with these gaps: background colour placeholder (G2), font (G6), key mapping (G4).
- **L2** (same game-ID format; same ID gives the same puzzle): reached by construction — the start layout is a pure function of the description (C30), and the ID parser follows C21–C23.
- **L3** (same seed gives the same puzzle as the original generator): implemented (C10–C15, C24–C29) but **not verified** against the original before the key (G11).
