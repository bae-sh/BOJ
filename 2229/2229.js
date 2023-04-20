const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const arr = input[1].split(' ').map(Number);
const dp = new Array(N).fill(0);

for (let i = 0; i < N; i++) {
  let [minValue, maxValue] = [arr[i], arr[i]];
  for (let j = i; j >= 0; j--) {
    const value = arr[j];
    minValue = Math.min(minValue, value);
    maxValue = Math.max(maxValue, value);
    const gap = maxValue - minValue;

    if (j === 0) dp[i] = Math.max(gap, dp[i]);
    else dp[i] = Math.max(dp[j - 1] + gap, dp[i]);
  }
}

console.log(dp[N - 1]);
