const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const a = new Set(input[1].split(' '));
const b = new Set(input[2].split(' '));
let ans = a.size + b.size;

for (let item of b) {
  if (a.has(item)) {
    ans -= 2;
  }
}

console.log(ans);
