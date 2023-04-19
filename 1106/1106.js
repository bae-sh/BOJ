const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [C, N] = input.shift().split(' ').map(Number);
const dp = new Array(C + 1).fill(Number.MAX_SAFE_INTEGER);
let answer = Number.MAX_SAFE_INTEGER;

dp[0] = 0;
for (let i = 0; i < N; i++) {
  const [cost, value] = input.shift().split(' ').map(Number);
  for (let j = 0; j <= C; j++) {
    if (j + value <= C) dp[j + value] = Math.min(dp[j + value], dp[j] + cost);

    if (j + value >= C) answer = Math.min(answer, dp[j] + cost);
  }
}

console.log(answer);
