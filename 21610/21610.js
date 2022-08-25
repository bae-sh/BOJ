const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const dx = [0, -1, -1, -1, 0, 1, 1, 1];
const dy = [-1, -1, 0, 1, 1, 1, 0, -1];

const arr = [];
const order = [];
const cloudPos = [
  { x: N - 2, y: 0 },
  { x: N - 2, y: 1 },
  { x: N - 1, y: 0 },
  { x: N - 1, y: 1 },
];

function init() {
  for (let i = 1; i <= N; i++) {
    arr.push(input[i].split(' ').map(Number));
  }

  for (let i = N + 1; i <= N + M; i++) {
    const [dir, speed] = input[i].split(' ').map(Number);
    order.push({ dir: dir - 1, speed });
  }
}

function playGame() {
  for (let i = 0; i < M; i++) {
    const nextCloudPos = [];
    const { dir, speed } = order[i];
    const cloudArr = Array.from({ length: N }, () => new Array(N).fill(false));

    moveCloud({ nextCloudPos, dir, speed, cloudArr });
    getWater({ nextCloudPos });
    makeCloud({ cloudArr });
  }
}

function moveCloud({ nextCloudPos, dir, speed, cloudArr }) {
  while (cloudPos.length !== 0) {
    const { x, y } = cloudPos.pop();

    let nx = x + ((dx[dir] * speed) % N);
    let ny = y + ((dy[dir] * speed) % N);

    nx = nx < 0 ? nx + N : nx < N ? nx : nx - N;
    ny = ny < 0 ? ny + N : ny < N ? ny : ny - N;

    nextCloudPos.push({ nx, ny });
    arr[nx][ny] += 1;
    cloudArr[nx][ny] = true;
  }
}

function getWater({ nextCloudPos }) {
  nextCloudPos.forEach(({ nx, ny }) => {
    for (let i = 1; i < 8; i += 2) {
      const nnx = nx + dx[i];
      const nny = ny + dy[i];
      if (0 <= nnx && nnx < N && 0 <= nny && nny < N) {
        if (arr[nnx][nny] > 0) {
          arr[nx][ny] += 1;
        }
      }
    }
  });
}

function makeCloud({ cloudArr }) {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (arr[i][j] >= 2 && !cloudArr[i][j]) {
        cloudPos.push({ x: i, y: j });
        arr[i][j] -= 2;
      }
    }
  }
}

function sumWater() {
  let sum = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      sum += arr[i][j];
    }
  }

  return sum;
}

init();
playGame();
const ans = sumWater();

console.log(ans);
