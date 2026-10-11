# PROVENANCE — target binary

| Field | Value |
|---|---|
| File | target/untangle.exe |
| URL | https://www.chiark.greenend.org.uk/~sgtatham/puzzles/untangle.exe |
| Download time | 2026-10-10T22:35:55-07:00 |
| HTTP status | 200 |
| Server Last-Modified | Wed, 23 Sep 2026 05:00:02 GMT |
| Size | 167,496 bytes |
| SHA-256 | 1012C8EE95CEF698A442227CAA2F54CAAA48C37D94392B736E772A17B2163DE3 |

## How the link was found
- Index page saved with `Invoke-WebRequest` to the scratchpad (36,876 bytes). Page text not read.
- Regex 1: `href="[^"]*untangle[^"]*\.exe"` (case-insensitive). Match: `href="untangle.exe"` (one match only).
- Regex 2 (to check for other Windows builds): `href="[^"]*\.(msi|exe|zip)"`. Matches: 40 per-game `.exe`, `puzzles.zip`, `puzzles-installer.msi`. No link names a 32-bit or 64-bit variant.
- Regex 3: `<base[^>]*>`. No match, so the relative link resolves against the page URL.
- The "64-bit" property is not provable from the regex output. Phase 2 checks the architecture with REA.
- No installer extraction was necessary: a direct `.exe` exists.
