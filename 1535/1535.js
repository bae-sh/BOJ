const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const hp = input[1].split(' ').map(Number);
const happy = input[2].split(' ').map(Number);
const dp = new Array(101).fill(0);

for (let i = 0; i < N; i++) {
  const [curHp, curHappy] = [hp[i], happy[i]];

  for (let j = 100; j > 0; j--) {
    const nextHp = j - curHp;
    if (nextHp > 0) dp[j] = Math.max(dp[j], dp[nextHp] + curHappy);
  }
}

console.log(Math.max(...dp));
