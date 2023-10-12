const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [M, N] = input.shift().split(' ').map(Number);
const dx = [0, -1, 0, 1];
const dy = [-1, 0, 1, 0];
const bits = [1, 2, 4, 8];

const visited = Array.from({ length: N }, () => new Array(M).fill(0));
const roomSize = new Array(N * M + 1).fill(0);

const field = [];
for (let i = 0; i < N; i++) {
  const arr = input.shift().split(' ').map(Number);
  field.push(arr);
}

let flag = 1;
let biggestSize = 0;
let sumest = 0;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (visited[i][j] !== 0) continue;
    bfs(i, j, flag);
    biggestSize = Math.max(biggestSize, roomSize[flag]);
    flag += 1;
  }
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    for (let k = 0; k < 4; k++) {
      const nx = i + dx[k];
      const ny = j + dy[k];
      if (!(0 <= nx && nx < N && 0 <= ny && ny < M)) continue;
      if (canGo(field[i][j], bits[k])) continue;
      if (visited[i][j] === visited[nx][ny]) continue;
      sumest = Math.max(sumest, roomSize[visited[i][j]] + roomSize[visited[nx][ny]]);
    }
  }
}
console.log(flag - 1);
console.log(biggestSize);
console.log(sumest);

function bfs(x, y, flag) {
  const queue = [{ x, y }];
  visited[x][y] = flag;
  roomSize[flag] += 1;

  while (queue.length > 0) {
    const { x, y } = queue.pop();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (!(0 <= nx && nx < N && 0 <= ny && ny < M)) continue;
      if (!canGo(field[x][y], bits[i])) continue;
      if (visited[nx][ny] !== 0) continue;

      visited[nx][ny] = flag;
      roomSize[flag] += 1;
      queue.push({ x: nx, y: ny });
    }
  }
}

function canGo(x, y) {
  return (x & y) === 0;
}
