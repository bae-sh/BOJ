const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];

const dp = new Array(N + 1).fill(-1);

dp[N] = 1;

function go(n) {
  if (n - 3 > 0 && dp[n - 1] === -1) {
    dp[n - 3] = (dp[n] + 1) % 2;
    go(n - 3);
  }
  if (n - 1 > 0 && dp[n - 1] === -1) {
    dp[n - 1] = (dp[n] + 1) % 2;
    go(n - 1);
  }
}
go(N);

if (dp[1] === 0 || dp[3] === 0) console.log('SK');
else console.log('CY');
