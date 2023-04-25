const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const n = +input[0];

let [A, B, C] = [1, 0, 1];
for (let i = 2; i <= n; i++) {
  let [a, b, c] = [A, B, C];
  A = (a + b) % 10;
  B = c;
  C = (a + b) % 10;
}

console.log((A + B) % 10);
