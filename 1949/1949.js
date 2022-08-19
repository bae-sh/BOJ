const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = [0, ...input[1].split(' ').map(Number)];
const v = Array.from({ length: N + 1 }, () => []);
const dp = Array.from({ length: N + 1 }, () => new Array(2).fill(0));
const visited = new Array(N + 1).fill(false);

for (let i = 2; i <= N; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  v[a].push(b);
  v[b].push(a);
}

function dfs(now) {
  visited[now] = true;

  dp[now][0] = 0;
  dp[now][1] = arr[now];

  v[now].forEach(next => {
    if (!visited[next]) {
      dfs(next);

      dp[now][0] += Math.max(dp[next][0], dp[next][1]);
      dp[now][1] += dp[next][0];
    }
  });
}

dfs(1);
console.log(Math.max(dp[1][0], dp[1][1]));
