const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];

const rates = [
  [
    { x: -1, y: 1, rate: 0.01 },
    { x: 1, y: 1, rate: 0.01 },
    { x: -1, y: 0, rate: 0.07 },
    { x: 1, y: 0, rate: 0.07 },
    { x: -1, y: -1, rate: 0.1 },
    { x: 1, y: -1, rate: 0.1 },
    { x: 0, y: -2, rate: 0.05 },
    { x: -2, y: 0, rate: 0.02 },
    { x: 2, y: 0, rate: 0.02 },
  ],
  [
    { x: -1, y: -1, rate: 0.01 },
    { x: -1, y: 1, rate: 0.01 },
    { x: 0, y: -1, rate: 0.07 },
    { x: 0, y: 1, rate: 0.07 },
    { x: 1, y: -1, rate: 0.1 },
    { x: 1, y: 1, rate: 0.1 },
    { x: 2, y: 0, rate: 0.05 },
    { x: 0, y: -2, rate: 0.02 },
    { x: 0, y: 2, rate: 0.02 },
  ],
  [
    { x: -1, y: -1, rate: 0.01 },
    { x: 1, y: -1, rate: 0.01 },
    { x: -1, y: 0, rate: 0.07 },
    { x: 1, y: 0, rate: 0.07 },
    { x: -1, y: 1, rate: 0.1 },
    { x: 1, y: 1, rate: 0.1 },
    { x: 0, y: 2, rate: 0.05 },
    { x: -2, y: 0, rate: 0.02 },
    { x: 2, y: 0, rate: 0.02 },
  ],
  [
    { x: 1, y: -1, rate: 0.01 },
    { x: 1, y: 1, rate: 0.01 },
    { x: 0, y: -1, rate: 0.07 },
    { x: 0, y: 1, rate: 0.07 },
    { x: -1, y: -1, rate: 0.1 },
    { x: -1, y: 1, rate: 0.1 },
    { x: -2, y: 0, rate: 0.05 },
    { x: 0, y: -2, rate: 0.02 },
    { x: 0, y: 2, rate: 0.02 },
  ],
];

const N = +input[0];
const arr = [];
let answer = 0;

for (let i = 1; i <= N; i++) {
  const temp = input[i].split(' ').map(Number);
  arr.push(temp);
}

function go(curX, curY) {
  let [count, moveLen, dir] = [0, 1, 0];

  while (curX >= 0 && curY >= 0) {
    if (count == 2) {
      count = 0;
      moveLen += 1;
    }
    for (let i = 1; i <= moveLen; i++) {
      const nx = curX + dx[dir];
      const ny = curY + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) return;
      const totalSand = arr[nx][ny];
      let leftSand = totalSand;
      rates[dir].forEach(({ x, y, rate }) => {
        const nnx = nx + x;
        const nny = ny + y;
        const sand = parseInt(totalSand * rate);

        if (0 <= nnx && nnx < N && 0 <= nny && nny < N) {
          arr[nnx][nny] += sand;
        } else {
          answer += sand;
        }
        leftSand -= sand;
      });
      const [nnx, nny] = [nx + dx[dir], ny + dy[dir]];
      if (0 <= nnx && nnx < N && 0 <= nny && nny < N) {
        arr[nnx][nny] += leftSand;
      } else {
        answer += leftSand;
      }
      arr[nx][ny] = 0;
      [curX, curY] = [nx, ny];
    }
    count += 1;
    dir = (dir + 1) % 4;
  }
}

go(parseInt(N / 2), parseInt(N / 2));
console.log(answer);
