const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const cost = input[1].split(' ').map(Number);
const dp = new Array(N + 1).fill(Infinity);

dp[0] = 0;

for (let i = 1; i <= N; i++) {
  for (let j = i; j <= N; j++) {
    dp[j] = Math.min(dp[j], dp[j - i] + cost[i - 1]);
  }
}

console.log(dp[N]);
