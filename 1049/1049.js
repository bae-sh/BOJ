const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
let items = Number.MAX_SAFE_INTEGER;
let item = Number.MAX_SAFE_INTEGER;

for (let i = 0; i < M; i++) {
  const [a, b] = input.shift().split(' ').map(Number);
  items = Math.min(items, a);
  item = Math.min(item, b);
}

let answer = item * N;

answer = Math.min(answer, parseInt(N / 6) * items + (N % 6) * item, (parseInt(N / 6) + 1) * items);
console.log(answer);
