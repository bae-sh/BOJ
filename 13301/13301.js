const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const dp = new Array(N).fill(0);

dp[0] = 0n;
dp[1] = 1n;

for (let i = 2; i <= N; i++) {
  dp[i] = dp[i - 1] + dp[i - 2];
}
const answer = String(dp[N] * 4n + dp[N - 1] * 2n);
console.log(answer);
