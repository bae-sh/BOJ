const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const dp = new Array(N + 1).fill(0);

for (let i = 1; i <= N; i++) {
  dp[i] = dp[i - 1] + 1;
  for (let j = 3; j <= i; j++) {
    dp[i] = Math.max(dp[i], dp[i - j] * (j - 1));
  }
}
console.log(dp[N]);
