const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const arr = [];
const dp = Array.from({ length: N }, () => new Array(M).fill(0));
const check = Array.from({ length: N }, () => new Array(M).fill(0));

const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];

let ans = 0;

let isInfi = false;

for (let i = 1; i <= N; i++) {
  const temp = input[i].split('');
  arr.push(temp);
}

dfs(0, 0, 0);
if (isInfi) {
  console.log(-1);
} else {
  console.log(ans);
}

function dfs(x, y, count) {
  if (isInfi) return;
  for (let i = 0; i < 4; i++) {
    const power = arr[x][y];
    const nx = x + dx[i] * power;
    const ny = y + dy[i] * power;

    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
      if (dp[nx][ny] !== 0) {
        isInfi = true;
        return;
      }

      if (arr[nx][ny] === 'H') {
        ans = Math.max(ans, count + 1);
      } else if (check[nx][ny] < count + 1) {
        dp[nx][ny] = count + 1;
        check[nx][ny] = count + 1;
        dfs(nx, ny, dp[nx][ny]);
        dp[nx][ny] = 0;
      }
    } else {
      ans = Math.max(ans, count + 1);
    }
  }
}
2;
