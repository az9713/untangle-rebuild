// Build receipt/rebuild-receipt.html from the repo files. Usage: node receipt/build-receipt.js <repo-root>
const fs = require("fs"), path = require("path"), { execFileSync } = require("child_process");
const root = process.argv[2], rd = f => fs.readFileSync(path.join(root, f), "utf8");
const esc = s => String(s).replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");
const md = s => esc(s).replace(/`([^`]+)`/g, "<code>$1</code>").replace(/\*\*([^*]+)\*\*/g, "<strong>$1</strong>");
const rows = (text, re) => text.split("\n").filter(l => re.test(l)).map(l => l.trim().replace(/^\||\|$/g, "").split(" | ").map(s => s.trim()));

const prompt = rd("rebuild-prompt.md");
const findings = rd("findings-before-key.md"), addendum = rd("findings-addendum.md"), grading = rd("grading.md");
const ledger = JSON.parse(rd("receipt/tool-ledger.json"));
const gitlog = execFileSync("git", ["-C", root, "log", "--reverse", "--format=%h%x09%ci%x09%s"]).toString().trim().split("\n").map(l => l.split("\t"));
const sha = f => require("crypto").createHash("sha256").update(fs.readFileSync(path.join(root, f))).digest("hex").toUpperCase();

const claims = rows(findings, /^\| C\d+ \|/), adds = rows(addendum, /^\| 2026/);
const verdict = {}; rows(grading.split("## Counts")[0], /^\| [CA]\d+ \|/).forEach(r => verdict[r[0]] = r);
const gaps = rows(findings, /^\| G\d+ \|/);
const gapCheck = {}; grading.split("## Gap check")[1].split("\n").forEach(l => { const m = /^- \*\*(G\d+):\*\* (.*)/.exec(l); if (m) gapCheck[m[1]] = m[2]; });
const cls = v => /^correct/.test(v) ? "ok" : /partly/.test(v) ? "part" : /wrong/.test(v) ? "bad" : "";

const claimRows = claims.map(c => { const v = verdict[c[0]] || []; return `<tr><td>${c[0]}</td><td>${md(c[1])}</td><td>${md(c[2])}</td><td>${esc(c[3])}</td><td class="${cls(v[1] || "")}">${esc(v[1] || "")}</td><td>${md(v[2] || "")}${v[3] ? "<br><span class=meta>" + md(v[3]) + "</span>" : ""}</td></tr>`; }).join("\n");
const addRows = adds.map(a => { const v = verdict[a[1]] || []; return `<tr><td>${a[1]}</td><td>${esc(a[0])}</td><td>${md(a[2])}</td><td>${md(a[3])}</td><td class="${cls(v[1] || "")}">${esc(v[1] || "")}</td><td>${md(v[2] || "")}</td></tr>`; }).join("\n");
const gapRows = gaps.map(g => `<tr><td>${g[0]}</td><td>${md(g[1])}</td><td>${md(g[2])}</td><td>${md(gapCheck[g[0]] || "")}</td></tr>`).join("\n");
const commitRows = gitlog.map(([h, t, s]) => `<tr><td><code>${h}</code></td><td>${esc(t)}</td><td>${esc(s)}</td></tr>`).join("\n");

const phases = [...new Set(ledger.counts.map(c => c.phase))], tools = [...new Set(ledger.counts.map(c => c.tool))].sort();
const cnt = (p, t) => (ledger.counts.find(c => c.phase === p && c.tool === t) || { n: "" }).n;
const ledgerTable = `<tr><th>Tool</th><th>Kind</th>${phases.map(p => `<th>${esc(p)}</th>`).join("")}<th>Total</th></tr>` + tools.map(t => {
  const tot = ledger.counts.filter(c => c.tool === t).reduce((a, c) => a + c.n, 0);
  return `<tr><td><code>${esc(t.replace("mcp__rea__", ""))}</code></td><td>${t.startsWith("mcp__rea__") ? '<span class="tag rea">REA</span>' : '<span class="tag out">outside REA</span>'}</td>${phases.map(p => `<td>${cnt(p, t)}</td>`).join("")}<td>${tot}</td></tr>`;
}).join("\n");
const nonRea = ledger.calls.filter(c => !c.rea).map(c => `<tr><td>${esc(c.time.slice(11, 19))}</td><td>${esc(c.phase)}</td><td><code>${esc(c.tool)}</code></td><td>${esc(c.reason)}</td></tr>`).join("\n");
const nRea = ledger.calls.filter(c => c.rea).length, nAll = ledger.calls.length;

const gif = fs.readFileSync(path.join(root, "receipt/side-by-side.gif")).toString("base64");
const rebuild = rd("rebuild/index.html");
const fbkSha = sha("findings-before-key.md"), binSha = sha("target/untangle.exe"), bundleSha = rd("evidence/bundle-phase2.sha256").trim();
const toolLog = rd("tool-log.md");

let html = fs.readFileSync(path.join(root, "receipt/template.html"), "utf8")
  .replace("{{PROMPT}}", esc(prompt)).replace("{{COMMITS}}", commitRows).replace("{{CLAIMS}}", claimRows).replace("{{ADDS}}", addRows)
  .replace("{{GAPS}}", gapRows).replace("{{LEDGER}}", ledgerTable).replace("{{NONREA}}", nonRea).replace("{{GIF}}", gif)
  .replace("{{REBUILD}}", esc(rebuild).replace(/"/g, "&quot;")).replace("{{FBKSHA}}", fbkSha).replace("{{BINSHA}}", binSha)
  .replace("{{BUNDLESHA}}", bundleSha).replace(/\{\{NREA\}\}/g, nRea).replace(/\{\{NALL\}\}/g, nAll).replace("{{TOOLLOG}}", esc(toolLog));
// Personal data removal: user name in paths and the session ID.
html = html.replace(/(Users[\\/]+)<user>/gi, "$1&lt;user&gt;").replace(/Users-<user>/gi, "Users-&lt;user&gt;").replace(/The user sent/g, "&lt;user&gt; sent").replace(/<session-id>/g, "&lt;session-id&gt;").replace(/<session-id-2>/g, "&lt;session-id-2&gt;");
fs.writeFileSync(path.join(root, "receipt/rebuild-receipt.html"), html);
console.log("written", html.length, "bytes; leftover '<user>' in paths:", (html.match(/Users[\\/]+<user>/gi) || []).length);
