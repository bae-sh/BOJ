const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
let lineIndex = 0;
const [N, d, k, c] = input[lineIndex++].split(' ').map(Number);

const dp = new Array(d + 1).fill(0);
const order = [];
let count = 0;
let coupon = false;
let answer = 0;

for (let i = 0; i < N; i++) {
  order.push(+input[lineIndex++]);
}

for (let i = 1; i < k; i++) {
  order.push(+input[i]);
}

for (let i = 0; i < k; i++) {
  const num = order[i];
  dp[num] += 1;
  if (dp[num] === 1) {
    count += 1;
    if (num === c) coupon = true;
  }
}

answer = Math.max(answer, coupon ? count : count + 1);

for (let i = k; i < order.length; i++) {
  const lastNum = order[i - k];
  dp[lastNum] -= 1;
  if (dp[lastNum] === 0) {
    count -= 1;
    if (lastNum === c) coupon = false;
  }

  const num = order[i];
  dp[num] += 1;
  if (dp[num] === 1) {
    count += 1;
    if (num === c) coupon = true;
  }
  answer = Math.max(answer, coupon ? count : count + 1);
}

console.log(answer);
