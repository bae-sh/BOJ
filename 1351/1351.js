const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dp = { 0: 1 };
const [N, P, Q] = input[0].split(' ').map(Number);

console.log(getA(N));

function getA(value) {
  if (dp[value]) return dp[value];

  dp[value] = getA(Math.floor(value / P)) + getA(Math.floor(value / Q));
  return dp[value];
}
