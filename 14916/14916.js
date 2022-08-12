const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];

const dp = new Array(N + 1).fill(Infinity);
dp[2] = 1;
dp[4] = 2;
dp[5] = 1;

for (let i = 6; i <= N; i++) {
  dp[i] = Math.min(dp[i - 2] + 1, dp[i - 5] + 1);
}

if (dp[N] === Infinity) {
  console.log(-1);
} else {
  console.log(dp[N]);
}
