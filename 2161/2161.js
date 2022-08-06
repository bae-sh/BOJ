const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];

const q = [];
let ans = '';

for (let i = 1; i <= N; i++) {
  q.push(i);
}

game();

console.log(ans);
function game() {
  while (q.length > 1) {
    ans += q.shift() + ' ';
    const next = q.shift();
    q.push(next);
  }
  ans += q.pop();
}
