const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M, T] = input.shift().split(' ').map(Number);
const field = [];
for (let i = 0; i < N; i++) {
  field.push(input.shift().split(' ').map(Number));
}
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
let ans = -1;

function bfs() {
  const visited = Array.from({ length: N }, () => new Array(M).fill(false));
  const gramVisited = Array.from({ length: N }, () => new Array(M).fill(false));

  const q = [];
  q.push({ x: 0, y: 0, hasGram: false, count: 0 });
  visited[0][0] = true;

  while (q.length !== 0) {
    const { x, y, hasGram, count } = q.shift();

    if (x === N - 1 && y === M - 1) {
      if (count <= T) {
        ans = count;
      }
      return;
    }
    const curVisit = hasGram ? gramVisited : visited;
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (!curVisit[nx][ny]) {
          if (field[nx][ny] === 0 || (hasGram && field[nx][ny] === 1)) {
            curVisit[nx][ny] = true;
            q.push({ x: nx, y: ny, hasGram: hasGram, count: count + 1 });
          }
          if (field[nx][ny] === 2) {
            curVisit[nx][ny] = true;
            q.push({ x: nx, y: ny, hasGram: true, count: count + 1 });
          }
        }
      }
    }
  }
}

bfs();
console.log(ans === -1 ? 'Fail' : ans);
