const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const T = +input[0];
const dp = new Array(10001).fill(0); //1,2로 만드는 경우

dp[0] = 1;
for (let i = 1; i <= 10001; i++) {
  dp[i] = Math.floor(i / 2) + 1;
}

for (let i = 0; i < T; i++) {
  const n = +input[i + 1];
  let answer = 0;
  for (let j = n; j >= 0; j -= 3) {
    answer += dp[j];
  }
  console.log(answer);
}
