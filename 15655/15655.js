const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const arr = input.shift().split(' ').map(Number);
let ans = '';

arr.sort((a, b) => {
  return a - b;
});

function go(start, count, str) {
  if (count === M) {
    ans += `${str.trim()}\n`;
    return;
  }
  if (start >= N) return;
  go(start + 1, count + 1, `${str} ${arr[start]}`);
  go(start + 1, count, str);
}

go(0, 0, '');

console.log(ans);
