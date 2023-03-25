const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const arr = [];
let answer = Number.MAX_SAFE_INTEGER;

for (let i = 0; i < N; i++) {
  const n = +input.shift();
  arr.push(n);
}

arr.sort((a, b) => {
  return a - b;
});
let [l, r] = [0, 1];

while (r < N) {
  const gap = arr[r] - arr[l];
  if (l == r) r += 1;
  if (gap >= M) {
    answer = Math.min(answer, gap);
    l += 1;
  } else {
    r += 1;
  }
}

console.log(answer);
