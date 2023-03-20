const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const arr = input.shift().split(' ').map(Number);
let ans = '';

arr.sort((a, b) => {
  return a - b;
});

function go(count, str) {
  if (count >= M) {
    ans += `${str.trim()}\n`;
    return;
  }
  for (let i = 0; i < N; i++) {
    go(count + 1, `${str} ${arr[i]}`);
  }
}

go(0, '');

console.log(ans);
