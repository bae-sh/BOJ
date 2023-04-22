const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const str = input[0].split('').map(Number);

const dp = [1, ...new Array(str.length).fill(0)];

dp[1] = 1;

for (let i = 2; i <= str.length; i++) {
  if (0 < str[i - 1]) dp[i] += dp[i - 1];
  if (10 <= str[i - 2] * 10 + str[i - 1] && str[i - 2] * 10 + str[i - 1] <= 34) {
    dp[i] += dp[i - 2];
  }
}

console.log(dp[str.length]);
