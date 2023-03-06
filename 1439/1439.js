const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const str = input[0].split('').map(Number);

let arr = [0, 0];
arr[str[0]] += 1;

for (let i = 0; i < str.length - 1; i++) {
  if (str[i] !== str[i + 1]) {
    arr[str[i + 1]] += 1;
  }
}

console.log(Math.min(...arr));
