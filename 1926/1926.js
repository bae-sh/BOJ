const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [n, m] = input.shift().split(' ').map(Number);
const field = [];
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];
let count = 1;
let answer = 0;

for (let i = 0; i < n; i++) {
  const temp = input.shift().split(' ').map(Number);
  field.push(temp);
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (field[i][j] === 1) {
      count += 1;
      bfs(i, j);
    }
  }
}
function bfs(x, y) {
  const q = [{ x, y }];
  field[x][y] = count;
  let sum = 1;

  while (q.length !== 0) {
    const { x, y } = q.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        if (field[nx][ny] === 1) {
          field[nx][ny] = count;
          sum += 1;
          q.push({ x: nx, y: ny });
        }
      }
    }
  }

  answer = Math.max(sum, answer);
}

console.log(count - 1);
console.log(answer);
