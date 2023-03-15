const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
let answer = '';
function go(num, from, by, to) {
  if (num == 1) answer += `${from} ${to}\n`;
  else {
    go(num - 1, from, to, by);
    answer += `${from} ${to}\n`;
    go(num - 1, by, from, to);
  }
}

console.log(String(BigInt(2 ** N) - 1n));

if (N <= 20) {
  go(N, 1, 2, 3);
  console.log(answer);
}
