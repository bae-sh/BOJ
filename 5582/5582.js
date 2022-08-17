const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const str1 = input[0].split('');
const str2 = input[1].split('');
const dp = Array.from({ length: str2.length + 1 }, () => new Array(str1.length + 1).fill(0));

let ans = 0;

for (let i = 1; i <= str2.length; i++) {
  for (let j = 1; j <= str1.length; j++) {
    if (str1[j - 1] === str2[i - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
      ans = Math.max(ans, dp[i][j]);
    }
  }
}

console.log(ans);
