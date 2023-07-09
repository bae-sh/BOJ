const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const start = input[0];
const end = input[1];

let answer = 0;

function go(str) {
  if (str === start) {
    answer = 1;
    return;
  }
  if (str.length <= start.length) return;

  if (str[str.length - 1] === 'A') {
    const arr = str.split('');
    arr.pop();
    go(arr.join(''));
  }
  if (str[0] === 'B') {
    const arr = str.split('').reverse();
    arr.pop();
    go(arr.join(''));
  }
}

go(end);
console.log(answer);
