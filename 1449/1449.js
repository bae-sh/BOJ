const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, L] = input.shift().split(' ').map(Number);
const arr = input.shift().split(' ').map(Number);

arr.sort((a, b) => a - b);

let cur = 0;
let answer = 0;
arr.forEach(pos => {
  if (pos >= cur) {
    cur = pos + L;
    answer += 1;
  }
});

console.log(answer);
