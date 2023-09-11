const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const set1 = new Set(input[1].split(' ').map(Number));
const set2 = new Set(input[3].split(' ').map(Number));

const result = [];
for (let num of set2) {
  if (set1.has(num)) {
    result.push(1);
  } else {
    result.push(0);
  }
}

console.log(result.join(' '));
