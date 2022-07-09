const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const dp = Array.from({ length: N + 1 }, () => new Array(2));

dp[0][0] = 1;
dp[0][1] = 0;
for (let i = 1; i <= N; i++) {
  dp[i][0] = dp[i - 1][1];
  dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
}

console.log(dp[N][0] + ' ' + dp[N][1]);
