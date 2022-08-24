const fs = require('fs');
const N = +fs.readFileSync('input.txt').toString();
const MOD = 10e8 + 7;

const dp = Array.from({ length: N + 2 }, () => new Array(4).fill(1));
dp[1][3] = 2;

for (let i = 2; i <= N; i++) {
  dp[i][0] = dp[i - 1][3];
  dp[i][1] = (dp[i - 1][3] + dp[i - 1][2]) % MOD;
  dp[i][2] = (dp[i - 1][3] + dp[i - 1][1]) % MOD;
  dp[i][3] = (dp[i - 1][3] * 2 + dp[i - 1][2] + dp[i - 1][1] + dp[i - 2][3]) % MOD;
}
console.log(dp[N][3]);
