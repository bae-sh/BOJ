const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const T = +input.shift();
const MOD = 1_000_000_007n;
const dp = new Array(5001).fill(0n);
dp[0] = 1n;
dp[2] = 1n;
for (let i = 4; i < 5001; i += 2) {
  for (let j = 2; j <= i; j += 2) {
    dp[i] += dp[i - j] * dp[j - 2];
    dp[i] %= MOD;
  }
}

for (let i = 0; i < T; i++) {
  const num = +input.shift();
  console.log(Number(dp[num]));
}
