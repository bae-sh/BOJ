//dfs를 돌면서 자기 자신과 같은 색상을 만나면 사이클 o
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

const [N, M] = input.shift().split(' ').map(Number);

const used = new Set();

const field = [];

let ans = 'No';

for (let i = 0; i < N; i++) {
  const arr = input.shift().split('');
  field.push(arr);
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    const char = field[i][j];
    if (used.has(char)) continue;
    const visited = Array.from({ length: N }, () => new Array(M).fill(false));
    visited[i][j] = true;
    dfs(i, j, visited, char, -1, -1);
  }
}

console.log(ans);

function dfs(x, y, visited, char, prevX, prevY) {
  if (ans === 'Yes') return;
  for (let i = 0; i < 4; i++) {
    const nx = x + dx[i];
    const ny = y + dy[i];

    if (!(0 <= nx && nx < N && 0 <= ny && ny < M)) continue;
    if (field[nx][ny] !== char) continue;

    if (visited[nx][ny]) {
      if (nx === prevX && ny === prevY) continue;
      ans = 'Yes';
      return;
    }
    visited[nx][ny] = true;
    dfs(nx, ny, visited, char, x, y);
    visited[nx][ny] = false;
  }
}
