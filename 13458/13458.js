const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);
const [B, C] = input[2].split(' ').map(Number);

let ans = 0;

arr.forEach(students => {
  students -= B;
  ans += 1;
  if (students > 0) {
    ans += Math.ceil(students / C);
  }
});

console.log(ans);
