const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M, R] = input[0].split(' ').map(Number);
let v = Array.from({ length: N + 1 }, () => []);
let visit = new Array(N + 1).fill(0);
let ans = new Array(N + 1).fill(0);
let count = 1;
for (let i = 1; i <= M; i++) {
  const [x, y] = input[i].split(' ').map(Number);
  v[x].push(y);
  v[y].push(x);
}

for (let i = 1; i <= N; i++) {
  v[i].sort().reverse();
}

function bfs(cur) {
  let q = [cur];
  visit[cur] = true;

  ans[cur] = count++;
  while (q.length) {
    const cur = q.shift();
    v[cur].map(next => {
      if (!visit[next]) {
        visit[next] = true;
        ans[next] = count++;
        q.push(next);
      }
    });
  }
}
bfs(R);
for (let i = 1; i <= N; i++) {
  console.log(ans[i]);
}
