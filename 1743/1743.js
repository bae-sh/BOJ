const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];

const [N, M, K] = input.shift().split(' ').map(Number);
const field = Array.from({ length: N }, () => new Array(M).fill(false));
const visited = Array.from({ length: N }, () => new Array(M).fill(false));

let ans = 0;

for (let i = 0; i < K; i++) {
  const [r, c] = input.shift().split(' ').map(Number);
  field[r - 1][c - 1] = true;
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (field[i][j] && !visited[i][j]) {
      visited[i][j] = true;
      bfs(i, j);
    }
  }
}

function bfs(x, y) {
  const q = [{ curX: x, curY: y }];
  let count = 1;

  while (q.length !== 0) {
    const { curX, curY } = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = curX + dx[i];
      const ny = curY + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (field[nx][ny] && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push({ curX: nx, curY: ny });
          count += 1;
        }
      }
    }
  }
  ans = Math.max(ans, count);
}

console.log(ans);
