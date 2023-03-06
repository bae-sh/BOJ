const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const map = [];
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

let answer = 1;
let highestValue = 0;

function bfs(height, visited, x, y) {
  const q = [{ x, y }];

  while (q.length !== 0) {
    const { x, y } = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (map[nx][ny] > height && !visited[nx][ny]) {
          q.push({ x: nx, y: ny });
          visited[nx][ny] = true;
        }
      }
    }
  }
}
function go(height) {
  let count = 0;
  const visited = Array.from({ length: N }, () => new Array(N).fill(false));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (map[i][j] > height && !visited[i][j]) {
        bfs(height, visited, i, j);
        count++;
      }
    }
  }
  answer = Math.max(answer, count);
}
for (let i = 1; i <= N; i++) {
  const arr = input[i].split(' ').map(Number);
  highestValue = Math.max(highestValue, ...arr);
  map.push(arr);
}

for (let i = 1; i < highestValue; i++) {
  go(i);
}

console.log(answer);
