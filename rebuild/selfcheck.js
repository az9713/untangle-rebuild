// Self-check for the game logic in index.html. Run: node rebuild/selfcheck.js
// It evaluates the logic part of the page script (no DOM) and asserts basic properties.
const fs = require("fs"), path = require("path"), assert = require("assert");
const html = fs.readFileSync(path.join(__dirname, "index.html"), "utf8");
const script = html.split("<script>")[1].split("// ---------------- drawing")[0];
const api = new Function(script + "; return { sha1, newDesc, randomNew, validateDesc, newState, executeMove, solveMove, cross };")();

const hex = b => Buffer.from(b).toString("hex");
assert.strictEqual(hex(api.sha1(new TextEncoder().encode("abc"))), "a9993e364706816aba3e25717850c26c9cd0d89d");

for (const [n, seed] of [[4, "1"], [6, "42"], [10, "123456789012345"], [15, "7"], [25, "999"]]) {
  const a = api.newDesc(n, api.randomNew(seed)), b = api.newDesc(n, api.randomNew(seed));
  assert.deepStrictEqual(a, b, "same seed, same puzzle");
  assert.strictEqual(api.validateDesc(n, a.desc), null);
  const st = api.newState(n, a.desc);
  assert.ok(!st.completed, "start layout must be tangled");
  const deg = new Array(n).fill(0); st.edges.forEach(([x, y]) => { deg[x]++; deg[y]++; });
  assert.ok(Math.max(...deg) <= 4, "max degree 4");
  const solved = api.executeMove(st, api.solveMove(st, a.aux).move);
  assert.ok(solved && solved.completed && solved.cheated, "solve gives a planar layout");
  console.log(`n=${n} seed=${seed} edges=${st.edges.length} desc=${a.desc}`);
}
assert.strictEqual(api.validateDesc(5, "0-0"), "Node linked to itself in game description");
assert.strictEqual(api.validateDesc(5, "0-9"), "Number out of range in game description");
assert.strictEqual(api.validateDesc(5, "0+1"), "Expected '-' after number in game description");
assert.strictEqual(api.validateDesc(5, "0-1;"), "Expected ',' after number in game description");
const P = (x, y) => ({ x, y, d: 1 });
assert.ok(api.cross(P(0, 0), P(2, 2), P(0, 2), P(2, 0)), "X crosses");
assert.ok(api.cross(P(0, 0), P(2, 0), P(1, 0), P(1, 1)), "touch counts");
assert.ok(!api.cross(P(0, 0), P(1, 0), P(2, 0), P(3, 0)), "collinear apart");
console.log("selfcheck OK");
