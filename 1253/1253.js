const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);
let answer = 0;
arr.sort((a, b) => a - b);

for (let i = 0; i < N; i++) {
  let [left, right] = [0, N - 1];
  while (left < right) {
    const sum = arr[left] + arr[right];
    if (arr[i] === sum) {
      if (i === left) left += 1;
      else if (i === right) right -= 1;
      else {
        answer += 1;
        break;
      }
    } else if (arr[i] < sum) right -= 1;
    else left += 1;
  }
}

console.log(answer);
