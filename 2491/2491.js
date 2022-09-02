const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);
const arr2 = new Array(N).fill(1);
const dp = new Array(N).fill(1);
let flag = true;

for (let i = 1; i < N; i++) {
  if (arr[i] === arr[i - 1]) {
    arr2[i] = arr2[i - 1] + 1;
    dp[i] = dp[i - 1] + 1;
  } else if (arr[i] > arr[i - 1]) {
    if (flag) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = arr2[i - 1] + 1;
      flag = true;
    }
  } else {
    if (!flag) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = arr2[i - 1] + 1;
      flag = false;
    }
  }
}

console.log(Math.max(...dp));
