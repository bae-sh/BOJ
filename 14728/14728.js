const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, T] = input[0].split(' ').map(Number);
const dp = Array.from({ length: N + 1 }, () => new Array(T + 1).fill(0));

for (let i = 1; i <= N; i++) {
  const [K, S] = input[i].split(' ').map(Number);

  for (let j = 1; j <= T; j++) {
    if (j >= K) {
      dp[i][j] = Math.max(dp[i - 1][j - K] + S, dp[i - 1][j]);
    } else {
      dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
}

console.log(dp[N][T]);
