const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
const field = [];
const [N, K] = input[0].split(' ').map(Number);
const virus = Array.from({ length: K + 1 }, () => []);
const [S, X, Y] = input[N + 1].split(' ').map(Number);

for (let i = 0; i < N; i++) {
  const arr = input[i + 1].split(' ').map(Number);
  arr.map((v, index) => {
    virus[v].push({ x: i, y: index });
  });
  field.push(arr);
}
infect();
console.log(field[X - 1][Y - 1]);
function infect() {
  for (let i = 0; i < S; i++) {
    for (let j = 1; j <= K; j++) {
      const preVirus = [...virus[j]];
      virus[j] = [];
      preVirus.map(({ x, y }) => {
        for (let k = 0; k < 4; k++) {
          const nx = x + dx[k];
          const ny = y + dy[k];
          if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (field[nx][ny] === 0) {
              field[nx][ny] = j;
              virus[j].push({ x: nx, y: ny });
            }
          }
        }
      });
    }
  }
}
