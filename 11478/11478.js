const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const size = input[0].length;
const ans = new Set();

for (let i = 0; i < size; i++) {
  for (let j = i; j < size; j++) {
    ans.add(input[0].substring(i, j + 1));
  }
}

console.log(ans.size);
