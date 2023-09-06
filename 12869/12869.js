const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const dp = Array.from({ length: 61 }, () =>
  Array.from({ length: 61 }, () => new Array(61).fill(Number.MAX_SAFE_INTEGER)),
);
dp[0][0][0] = 0;

const arr = input.shift().split(' ').map(Number);
for (let i = N; i < 3; i++) {
  arr.push(0);
}

function killSCV(a, b, c) {
  [a, b, c] = [a, b, c].sort((a, b) => b - a).map(item => (item < 0 ? 0 : item));

  if (dp[a][b][c] !== Number.MAX_SAFE_INTEGER) return dp[a][b][c];
  dp[a][b][c] = Math.min(
    killSCV(a - 9, b - 3, c - 1) + 1,
    killSCV(a - 9, b - 1, c - 3) + 1,
    killSCV(a - 3, b - 9, c - 1) + 1,
    killSCV(a - 3, b - 1, c - 9) + 1,
    killSCV(a - 1, b - 3, c - 9) + 1,
    killSCV(a - 1, b - 9, c - 3) + 1,
  );

  return dp[a][b][c];
}

console.log(killSCV(...arr));
