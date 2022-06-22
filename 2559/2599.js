const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, K] = input[0].split(' ').map(Number);
const arr = input[1].split(' ').map(Number);
const sum = new Array(N + 1);
let ans = -2100000000;
sum[0] = 0;

arr.map((item, idx) => (sum[idx + 1] = item + sum[idx]));
for (let i = K; i <= N; i++) {
  ans = Math.max(ans, sum[i] - sum[i - K]);
}
console.log(ans);
