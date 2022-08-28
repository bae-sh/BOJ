const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const leftCards = input[1].split(' ').map(Number);
const rightCards = input[2].split(' ').map(Number);

const dp = Array.from({ length: N + 1 }, () => new Array(N + 1).fill(-1));

console.log(getDp(0, 0));

function getDp(left, right) {
  if (left >= N || right >= N) return 0;

  if (dp[left][right] !== -1) return dp[left][right];

  if (leftCards[left] > rightCards[right])
    dp[left][right] = rightCards[right] + getDp(left, right + 1);
  else dp[left][right] = Math.max(getDp(left + 1, right), getDp(left + 1, right + 1));
  return dp[left][right];
}
