// Build the tool ledger from this session's transcript JSONL (not from memory).
// Usage: node receipt/build-ledger.js <transcript.jsonl> <repo-root> <out.json>
const fs = require("fs"), { execSync } = require("child_process");
const [, , jsonl, root, out] = process.argv;
// Phase boundaries = commit times from git log (the timeline proof).
const commits = execSync(`git -C "${root}" log --reverse --format=%cI%x09%s`).toString().trim().split("\n")
  .map(l => { const [t, s] = l.split("\t"); return { t: Date.parse(t), s }; });
// A call belongs to the first commit at or after it. Phase 6 ran while the phase 5 grader ran, so those calls land in "phase 5: grading".
const phaseOf = ts => { for (const c of commits) if (ts <= c.t) return c.s.replace(/ \(.*/, ""); return "phase 7: receipt"; };
const rows = [];
for (const line of fs.readFileSync(jsonl, "utf8").split("\n")) {
  if (!line.trim()) continue;
  let e; try { e = JSON.parse(line); } catch { continue; }
  if (e.type !== "assistant" || !e.message || !Array.isArray(e.message.content)) continue;
  for (const c of e.message.content) if (c.type === "tool_use") {
    const ts = Date.parse(e.timestamp);
    rows.push({ time: e.timestamp, phase: phaseOf(ts), tool: c.name, rea: c.name.startsWith("mcp__rea__"),
      reason: (c.input && (c.input.description || c.input.reason)) || "" });
  }
}
const byKey = {};
for (const r of rows) { const k = r.phase + "|" + r.tool; byKey[k] = (byKey[k] || 0) + 1; }
const counts = Object.entries(byKey).map(([k, n]) => { const [phase, tool] = k.split("|"); return { phase, tool, n }; });
fs.writeFileSync(out, JSON.stringify({ transcript: "<session-id>.jsonl", commits: commits.map(c => ({ time: new Date(c.t).toISOString(), subject: c.s })), counts, calls: rows }, null, 1));
console.log(`calls ${rows.length}, rea ${rows.filter(r => r.rea).length}, non-rea ${rows.filter(r => !r.rea).length}`);
