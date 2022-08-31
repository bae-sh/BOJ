const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const nextClass = Array.from({ length: N + 1 }, () => []);
const ans = new Array(N + 1).fill(1);
const q = [];

for (let i = 0; i < M; i++) {
  const [a, b] = input[i + 1].split(' ').map(Number);

  nextClass[a].push(b);
}

for (let i = 1; i <= N; i++) {
  nextClass[i].forEach(index => {
    ans[index] = Math.max(ans[index], ans[i] + 1);
  });
}
ans.shift();
console.log(ans.join(' '));
