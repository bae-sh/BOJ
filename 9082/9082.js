const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const T = +input[0];
let line = 1;

for (let i = 0; i < T; i++) {
  const N = input[line];
  const numbers = input[line + 1].split('').map(Number);
  const shapes = input[line + 2].split('');
  let ans = 0;
  checkMine(numbers, shapes, N);
  for (let i = 0; i < N; i++) {
    if (shapes[i] === '*') ans++;
  }
  console.log(ans);
  line += 3;
}

function checkMine(numbers, shapes, N) {
  for (let i = 0; i < N; i++) {
    const [a, b, c] = [i - 1, i, i + 1];

    if (0 <= a && a < N && shapes[i] === '*') numbers[a]--;
    if (0 <= b && b < N && shapes[i] === '*') numbers[b]--;
    if (0 <= c && c < N && shapes[i] === '*') numbers[c]--;
  }
  for (let i = 0; i < N; i++) {
    const [a, b, c] = [i - 1, i, i + 1];
    let res = true;
    if (0 <= a && a < N && numbers[a] === 0) res = false;
    if (0 <= b && b < N && numbers[a] === 0) res = false;
    if (0 <= c && c < N && numbers[c] === 0) res = false;
    if (res) {
      if (0 <= a && a < N) numbers[a]--;
      if (0 <= b && b < N) numbers[b]--;
      if (0 <= c && c < N) numbers[c]--;
      shapes[i] = '*';
    }
  }
}
