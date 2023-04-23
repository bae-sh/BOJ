const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const T = +input[0];

const arr = Array.from({ length: 65 }, () => new Array(10).fill(0));
for (let i = 0; i < 10; i++) {
  arr[1][i] = 1;
}
for (let i = 2; i <= 64; i++) {
  for (let j = 0; j < 10; j++) {
    for (let k = 0; k <= j; k++) {
      arr[i][j] += arr[i - 1][k];
    }
  }
}
for (let i = 0; i < T; i++) {
  const n = +input[i + 1];
  const answer = arr[n].reduce((prev, cur) => {
    return prev + cur;
  }, 0);
  console.log(answer);
}
