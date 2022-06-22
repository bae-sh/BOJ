const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M] = input[0].split(' ').map(Number);
const set = new Set();
let ans = 0;

for (let i = 1; i <= N; i++) {
  set.add(input[i]);
}
for (let i = N + 1; i <= N + M; i++) {
  if (set.has(input[i])) ans++;
}
console.log(ans);
