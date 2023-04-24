const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const T = +input.shift();

for (let i = 0; i < T; i++) {
  const N = +input.shift();
  const arr = input.shift().split(' ').map(Number);
  const M = +input.shift();
  const dp = new Array(M + 1).fill(0);

  for (const num of arr) {
    dp[num] += 1;
    for (let i = 1; i <= M; i++) {
      if (i - num < 0) continue;
      dp[i] += dp[i - num];
    }
  }

  console.log(dp[M]);
}
