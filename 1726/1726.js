//[동,서,남,북]
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const ways = [
  [2, 3],
  [2, 3],
  [0, 1],
  [0, 1],
];
const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

const [M, N] = input.shift().split(' ').map(Number);

const field = [];

const dp = Array.from({ length: M }, () =>
  Array.from({ length: N }, () => new Array(4).fill(Number.MAX_SAFE_INTEGER)),
);

for (let i = 0; i < M; i++) {
  const arr = input.shift().split(' ').map(Number);
  field.push(arr);
}

const [sx, sy, sway] = input
  .shift()
  .split(' ')
  .map(v => Number(v) - 1);
const [ex, ey, eway] = input
  .shift()
  .split(' ')
  .map(v => Number(v) - 1);

dp[sx][sy][sway] = 0;
let ans = Number.MAX_SAFE_INTEGER;

function bfs() {
  const queue = [{ x: sx, y: sy, way: sway }];
  if (sx === ex && sy === ey && sway === eway) {
    ans = 0;
    return;
  }
  while (queue.length > 0) {
    const { x, y, way } = queue.shift();
    move(x, y, way, queue);
    for (let i = 0; i < 2; i++) {
      const nway = ways[way][i];
      if (dp[x][y][nway] < dp[x][y][way] + 1) continue;
      dp[x][y][nway] = dp[x][y][way] + 1;
      if (x === ex && y === ey && nway === eway) {
        ans = Math.min(ans, dp[x][y][nway]);
        continue;
      }
      queue.push({ x, y, way: nway });
    }
  }
}

function move(x, y, way, queue) {
  for (let i = 1; i <= 3; i++) {
    const nx = x + dx[way] * i;
    const ny = y + dy[way] * i;
    if (!(0 <= nx && nx < M && 0 <= ny && ny < N)) continue;
    if (field[nx][ny] === 1) break;
    if (dp[nx][ny][way] <= dp[x][y][way] + 1) continue;
    dp[nx][ny][way] = dp[x][y][way] + 1;
    if (nx === ex && ny === ey && eway === way) {
      ans = Math.min(ans, dp[nx][ny][way]);
      return;
    }

    queue.push({ x: nx, y: ny, way: way });
  }
}
bfs();
console.log(ans);
