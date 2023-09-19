//열쇠 abcdef
//문 ABCDEF -> 열쇠가 있어야함
//민식이 현재 위치 '0'
//출구 1
//열쇠를 가지고 있는거와 dp 값이 같은경우 중복 제거
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [n, m] = input.shift().split(' ').map(Number);
const field = [];
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
const dp = Array.from({ length: n }, () => Array.from({ length: m }, () => new Array()));
let sx, sy;

for (let i = 0; i < n; i++) {
  const arr = input.shift().split('');
  field.push(arr);
  arr.forEach((item, index) => {
    if (item === '0') {
      [sx, sy] = [i, index];
    }
  });
}
console.log(bfs());

function bfs() {
  const queue = [{ x: sx, y: sy, cost: 0, key: '' }];
  dp[sx][sy].push('');
  while (queue.length > 0) {
    const { x, y, cost, key } = queue.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
      if (field[nx][ny] === '#') continue;
      if (field[nx][ny] === '1') return cost + 1;

      if ('A' <= field[nx][ny] && field[nx][ny] <= 'F') {
        if (key.split('').includes(field[nx][ny].toLowerCase())) {
          if (!duplicate(key, nx, ny)) {
            queue.push({ x: nx, y: ny, cost: cost + 1, key: key });
            dp[nx][ny].push(key);
          }
        }
      } else if ('a' <= field[nx][ny] && field[nx][ny] <= 'f') {
        if (!duplicate(key, nx, ny)) {
          const newKey = key + field[nx][ny];
          queue.push({ x: nx, y: ny, cost: cost + 1, key: newKey });
          dp[nx][ny].push(newKey);
        }
      } else if (field[nx][ny] === '.' || field[nx][ny] === '0') {
        if (!duplicate(key, nx, ny)) {
          queue.push({ x: nx, y: ny, cost: cost + 1, key: key });
          dp[nx][ny].push(key);
        }
      }
    }
  }

  return -1;
}

function duplicate(key, x, y) {
  let ans = false;
  dp[x][y].forEach(curKey => {
    let count = 0;
    key.split('').forEach(item => {
      if (curKey.split('').includes(item)) count += 1;
    });
    if (key.length === count) ans = true;
  });
  return ans;
}
