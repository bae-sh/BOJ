const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const M = +input.shift();

const v = Array.from({ length: N + 1 }, () => new Array());
const visited = new Array(N + 1).fill(false);
let ans = 0;
visited[1] = true;

for (let i = 0; i < M; i++) {
  const [x, y] = input.shift().split(' ').map(Number);
  v[x].push(y);
  v[y].push(x);
}

const q = [];
for (const next of v[1]) {
  q.push(next);
  visited[next] = true;
}

while (q.length !== 0) {
  const cur = q.shift();
  for (const next of v[cur]) {
    if (!visited[next]) {
      q.push(next);
      visited[next] = true;
    }
  }
}

for (let i = 2; i <= N; i++) {
  if (visited[i]) ans += 1;
}
console.log(ans);
