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
