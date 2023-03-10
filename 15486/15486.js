const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const dp = new Array(N + 2).fill(0);

for (let i = 1; i <= N; i++) {
  const [T, P] = input[i].split(' ').map(Number);
  const nextDay = i + T;

  dp[i] = Math.max(dp[i], dp[i - 1]);
  if (nextDay <= N + 1) {
    dp[nextDay] = Math.max(dp[nextDay], dp[i] + P);
  }
}
console.log(Math.max(dp[N], dp[N + 1]));
