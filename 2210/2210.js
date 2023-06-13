const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const field = [];
const ans = [];
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

for (let i = 0; i < 5; i++) {
  field.push(input.shift().split(' '));
}

for (let i = 0; i < 5; i++) {
  for (let j = 0; j < 5; j++) {
    bfs(field[i][j], i, j);
  }
}

function bfs(str, x, y) {
  if (str.length === 6) {
    if (!ans.includes(str)) ans.push(str);
    return;
  }

  for (let i = 0; i < 4; i++) {
    const nx = x + dx[i];
    const ny = y + dy[i];

    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
      bfs(str + field[nx][ny], nx, ny);
    }
  }
}

console.log(ans.length);
