const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const arr = [];

for (let i = 0; i < N; i++) {
  const temp = input[i + 1].split('').map(Number);
  arr.push(temp);
}

const ans = game();
console.log(ans * ans);

function game() {
  let start = Math.min(N, M);
  for (let i = start; i >= 1; i--) {
    for (let x = 0; x <= N - i; x++) {
      for (let y = 0; y <= M - i; y++) {
        const value = arr[x][y];
        if (
          value === arr[x + i - 1][y] &&
          value === arr[x][y + i - 1] &&
          value === arr[x + i - 1][y + i - 1]
        ) {
          return i;
        }
      }
    }
  }
}
