const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let lineIndex = 0;
const T = +input[lineIndex++];

for (let i = 0; i < T; i++) {
  const [n, d, c] = input[lineIndex++].split(' ').map(Number);
  const arr = Array.from({ length: n + 1 }, () => new Array(0));

  for (let j = 0; j < d; j++) {
    const [a, b, s] = input[lineIndex++].split(' ').map(Number);
    arr[b].push({ com: a, time: s });
  }

  
}
