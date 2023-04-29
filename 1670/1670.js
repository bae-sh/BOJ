const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const MOD = 987654321n;

const dp = new Array(N + 1).fill(-1);
dp[0] = 1;

function shake(num) {
  if (dp[num] !== -1) return dp[num];

  let value = 0;

  for (let i = 2; i <= num; i++) {
    const left = i - 2;
    const right = num - i;
    if (left % 2 == 0 && right % 2 == 0) {
      value = value + ((shake(left) * shake(right)) % MOD);
      value %= MOD;
    }
  }
  dp[num] = value;
  return value;
}

console.log(shake(N));
