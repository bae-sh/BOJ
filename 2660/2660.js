const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input.shift();

const friends = Array.from({ length: N + 1 }, () => new Array());
const dp = Array.from({ length: N + 1 }, () => new Array(N + 1).fill(0));

while (true) {
  const [a, b] = input.shift().split(' ').map(Number);
  if (a === -1 && b === -1) break;

  friends[a].push(b);
  friends[b].push(a);
}

const answer = [51, []];

for (let i = 1; i <= N; i++) {
  bfs(i);
  const count = Math.max(...dp[i]);
  if (count === answer[0]) answer[1].push(i);
  else if (count < answer[0]) {
    answer[0] = count;
    answer[1] = [i];
  }
}

console.log(answer[0], answer[1].length);
console.log(...answer[1]);
function bfs(index) {
  const visited = new Array(N + 1).fill(false);
  visited[index] = true;
  const q = [{ x: index, depth: 0 }];
  while (q.length !== 0) {
    const { x, depth } = q.shift();

    friends[x].forEach(nx => {
      if (!visited[nx]) {
        dp[index][nx] = depth + 1;
        q.push({ x: nx, depth: depth + 1 });
        visited[nx] = true;
      }
    });
  }
}
