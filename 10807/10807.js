const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);
const v = +input[2];

let count = 0;

arr.forEach(item => {
  if (item === v) count++;
});

console.log(count);
