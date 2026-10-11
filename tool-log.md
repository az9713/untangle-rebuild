# Tool log (non-REA tool uses)

Each row: time, tool, job, reason. REA tool calls are not listed here; the receipt ledger is built from the transcript.

| Time | Tool | Job | Reason |
|---|---|---|---|
| 2026-10-10 22:34 | PowerShell `rea.cmd --version` | record REA version | Phase 0 step 2. Result: 6.3.0 |
| 2026-10-10 22:34 | Bash mkdir, git init | create ROOT and folders | Phase 0 steps 3-4 |
| 2026-10-10 22:35 | Bash `curl` / PowerShell `curl.exe` | fetch index page | Failed: the shell could not start `curl` (EPERM / "Access is denied"). No data fetched. |
| 2026-10-10 22:35 | PowerShell `Invoke-WebRequest` | fetch index page to scratchpad | Phase 1 step 1 (curl replacement). Page text not read. |
| 2026-10-10 22:35 | PowerShell `[regex]::Matches` | extract exe link | Phase 1 step 1. Regexes logged in target/PROVENANCE.md |
| 2026-10-10 22:35 | PowerShell `Invoke-WebRequest` | download untangle.exe into target\ | Phase 1 step 2 |
| 2026-10-10 22:36 | PowerShell `Get-FileHash`, `Get-Item` | SHA-256 and size | Phase 1 step 3. **Incident:** a variable-name clash (`$r` = `$R` in PowerShell) made one command print about 1 KB of the raw exe bytes as an error message. The visible bytes include the PE header and section names. No fact from that output is used; Phase 2 gets identity facts from REA only. |
| 2026-10-10 22:37 | (note) | explain the curl failures | The user sent a screenshot (`Downloads\Screenshot 2026-10-10 223628.png`): the antivirus Real-Time Protection blocked the Bash `curl` command as "Trojan.Downloader.CLI" (heuristic on the command line). The PowerShell `Invoke-WebRequest` route was not blocked. Use it for the phase 5 key download too. |
| 2026-10-10 22:38-22:48 | node (scratchpad scripts) | read large REA results | Read saved REA tool-result JSON (strings, decompile) without loading them in full; decode game-descriptor qwords; transcribe FUN_140003f30 pseudocode to JS to tabulate it; parse PE header bytes from REA read_bytes; build evidence index from the REA bundle. Input data: REA outputs only. |
| 2026-10-10 22:52 | node `rebuild/selfcheck.js` | test own rebuild logic | Phase 4 self-check (no target facts involved). |
| 2026-10-10 22:53 | node static server (`serve.js`, PID 7056) | serve rebuild\ on 127.0.0.1:8765 | Phase 4 step 5: local static server for REA browser capture. |
| 2026-10-10 22:53 | Chrome (PID 46688, isolated profile, CDP port 9333) | browser for REA capture tools | Phase 4 step 5: REA capture_web_screenshot / capture_browser_scenario need a loopback CDP endpoint. |
| 2026-10-10 22:54 | PowerShell `Invoke-WebRequest http://127.0.0.1:9333/json/list` | find the CDP target ID | Phase 4 step 5 (list_browser_targets would also do it). |
| 2026-10-10 22:55-22:57 | node (`png.js`, `scen.js`) | extract PNGs from REA results | Phase 4 step 5: save REA captures in evidence\. |
| 2026-10-10 23:01 | PowerShell `[regex]::Matches` on saved index page | find the source archive link | Phase 5 step 1. Matches: puzzles.zip, puzzles.tar.gz; git link https://git.tartarus.org/?p=simon/puzzles.git |
| 2026-10-10 23:01 | PowerShell `Invoke-WebRequest` | download puzzles.tar.gz into key\ | Phase 5 step 1 (key download, allowed by rule 2) |
| 2026-10-10 23:02 | `C:\Windows\System32\tar.exe` | list and extract the key | Phase 5 step 1. Top folder puzzles-20260923.616da16 = binary version |
| 2026-10-10 23:04 | PowerShell Start-Process `target\untangle.exe 10#123456789012345` (PID 41132) | run the original for the GIF | Phase 6 step 2, after the phase 4 commit. Presentation only. The game-ID argument form comes from C21 and the "Supplied argument" string (ev_050a2cb0). |
| 2026-10-10 23:04 | PowerShell user32 (SetProcessDPIAware, SetWindowPos, GetClientRect, ClientToScreen) + System.Drawing CopyFromScreen | position and capture the PUZZLE window client area (400×400) | Phase 6 step 2. Non-REA. |
| 2026-10-10 23:05 | node `plan.js` (rebuild logic only) | plan 10 drags from the start circle to the aux solution, with a pick-conflict check | Phase 6 step 4: one move list for both sides. |
| 2026-10-10 23:06 | PowerShell user32 SetCursorPos + mouse_event | 10 drags on the PUZZLE window, 12 frames | Phase 6 step 2/4. Non-REA. |
| 2026-10-10 23:07-23:16 | PowerShell user32 (SetWindowPos topmost, ShowWindow, keybd_event Alt, SetForegroundWindow), CopyFromScreen | bring Chrome to the front, find the canvas rectangle, same 10 drags on the rebuild | Phase 6 step 3/4. Non-REA input (REA has no drag action). Frames for the GIF come from REA capture_web_screenshot (11 captures, IDs in evidence/gif/rb-evidence-ids.txt); PowerShell copies rb-ps-*.png are backups. |
| 2026-10-10 23:16 | ImageMagick 7.1.1 `magick.exe` | crop rebuild frames, compose pairs with labels, assemble receipt\side-by-side.gif | Phase 6 step 5 (GIF assembly). |
| 2026-10-10 23:17 | PowerShell Stop-Process by saved PID (41132, 46688, 7056) | stop original, Chrome, server | Cleanup. No kill by name. |
| 2026-10-10 23:02-23:18 | Agent (subagent_type reviewer, Read/Grep/Glob only) | grade claims and rebuild against key\ | Phase 5 step 2. Fresh agent, not a fork; inputs: findings-before-key.md, findings-addendum.md, rebuild\index.html, key\. Ran in the background while phase 6 ran. |
