const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const k = +input[0];
const [w, h] = input[1].split(' ').map(Number);
const field = [];
const dp = Array.from({ length: h }, () =>
  Array.from({ length: w }, () => new Array(k + 1).fill(Number.MAX_SAFE_INTEGER)),
);

dp[0][0][0] = 0;

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];
const dxj = [-2, -1, 1, 2, 2, 1, -1, -2];
const dyj = [1, 2, 2, 1, -1, -2, -2, -1];

let answer = Number.MAX_SAFE_INTEGER;

for (let i = 2; i < 2 + h; i++) {
  const arr = input[i].split(' ').map(Number);
  field.push(arr);
}

function bfs(x, y) {
  const q = [];
  q.push([x, y, 0]);
  while (q.length !== 0) {
    const [x, y, jump] = q.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        if (field[nx][ny] === 0) {
          if (dp[nx][ny][jump] > dp[x][y][jump] + 1) {
            dp[nx][ny][jump] = dp[x][y][jump] + 1;
            q.push([nx, ny, jump]);
          }
        }
      }
    }
    for (let i = 0; i < 8; i++) {
      const nx = x + dxj[i];
      const ny = y + dyj[i];

      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        if (field[nx][ny] === 0) {
          if (dp[nx][ny][jump + 1] > dp[x][y][jump] + 1) {
            dp[nx][ny][jump + 1] = dp[x][y][jump] + 1;
            q.push([nx, ny, jump + 1]);
          }
        }
      }
    }
  }
}

bfs(0, 0, 0);

for (let i = 0; i <= k; i++) {
  answer = Math.min(answer, dp[h - 1][w - 1][i]);
}

answer = answer === Number.MAX_SAFE_INTEGER ? -1 : answer;

console.log(answer);
