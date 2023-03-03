const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M] = input[0].split(' ').map(Number);

const field = [];
let ans = -1;

for (let i = 1; i <= N; i++) {
  const arr = input[i].split('').map(Number);
  field.push(arr);
}

function go() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      for (let k = 0; k < N; k++) {
        let num = '';

        for (let l = 0; l < M; l++) {
          const x = i + k;
          const y = j + l;
          if (0 <= x && x < N && 0 <= y && y < M) {
            const rev = num.split('').reverse().join('');
            num += field[x][y];
            if (check(Number(num))) {
              ans = Math.max(ans, Number(num));
            }
            if (check(Number(rev))) {
              ans = Math.max(ans, Number(rev));
            }
          }
        }
      }
    }
  }
}

function check(number) {
  return (number ** 0.5) ** 2 === number;
}
