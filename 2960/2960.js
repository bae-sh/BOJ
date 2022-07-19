const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, K] = input[0].split(' ').map(Number);

const ans = [];
const prime = new Array(N + 1).fill(true);

for (let i = 2; i <= N; i++) {
  for (let j = i; j <= N; j += i) {
    if (prime[j]) {
      ans.push(j);
      prime[j] = false;
    }
  }
}
console.log(ans[K - 1]);
