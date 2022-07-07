const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);

const dp = Array.from({ length: N + 1 }, () => new Array(2).fill(0));

let ans = -987654321;

for (let i = 1; i <= N; i++) {
  dp[i][0] = Math.max(dp[i - 1][0] + arr[i - 1], arr[i - 1]);
  dp[i][1] = Math.max(dp[i - 1][0], dp[i - 1][1] + arr[i - 1]);
  if (i === 1) {
    dp[i][1] = -987654321;
  }
  ans = Math.max(ans, dp[i][0], dp[i][1]);
}

console.log(ans);
