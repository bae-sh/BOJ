const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
let answer = 2;
for (let i = 1; i <= N; i++) {
  const str = input[i].split('');
  answer = 2;
  check(str, 0, str.length - 1, 0);
  console.log(answer);
}

function check(str, left, right, count) {
  if (right < left) return;
  if (left === right || (left + 1 === right && str[left] === str[right])) {
    if (count === 0) {
      answer = 0;
    } else if (count === 1) {
      answer = Math.min(answer, 1);
    }
    return;
  }

  if (str[left] === str[right]) {
    check(str, left + 1, right - 1, count);
  } else {
    if (count === 0) {
      check(str, left + 1, right, count + 1);
      check(str, left, right - 1, count + 1);
    }
  }
}
