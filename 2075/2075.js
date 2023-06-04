const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const n = +input[0];
let arr = [];

for (let i = 1; i <= n; i++) {
  const temp = input[i].split(' ').map(Number);

  for (const num of temp) {
    arr.push(num);
    arr.sort((a, b) => b - a);
    if (arr.length > 5) arr.pop();
  }
}
console.log(arr[n - 1]);
