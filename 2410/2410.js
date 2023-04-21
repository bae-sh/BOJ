const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const MOD = 1_000_000_000;
const dp = Array.from({ length: 1_000_001 }, () => new Array(20).fill(0));

for (let i = 0; i < 20; i++) {
  const num = 2 ** i;
  dp[num][i] = 1;
}

for (let i = 2; i <= N; i++) {
  for (let j = 0; j < 20; j++) {
    const num = 2 ** j;
    if (i < num) break;

    for (let k = 0; k <= j; k++) {
      dp[i][j] = (dp[i][j] + dp[i - num][k]) % MOD;
    }
  }
}

let answer = dp[N].reduce((prev, cur) => {
  return (prev + cur) % MOD;
}, 0);
console.log(answer);
