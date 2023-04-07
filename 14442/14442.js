class Queue {
  constructor() {
    this.queue = [];
    this.front = 0;
    this.rear = 0;
  }

  push(value) {
    this.queue[this.rear++] = value;
  }

  shift() {
    const value = this.queue[this.front];
    delete this.queue[this.front];
    this.front++;
    return value;
  }
  length() {
    return this.rear - this.front;
  }
}

const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const [N, M, K] = input[0].split(' ').map(Number);
const field = [];
const dp = new Array(N);
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

for (let i = 0; i < N; i++) {
  const arr = input[i + 1].split('').map(Number);
  field.push(arr);
}

for (let i = 0; i <= N; i++) {
  dp[i] = Array.from({ length: M }, () => new Array(K + 1).fill(-1));
}

function bfs() {
  const q = new Queue();
  q.push({ x: 0, y: 0, cost: 0, count: 1 });
  while (q.length() !== 0) {
    const { x, y, cost, count } = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (field[nx][ny] === 0) {
          if (dp[nx][ny][cost] === -1 || dp[nx][ny][cost] > count + 1) {
            const nextValue = { cost, x: nx, y: ny, count: count + 1 };
            fillDp(nextValue);
            q.push(nextValue);
          }
        } else {
          if (cost >= K) continue;
          if (dp[nx][ny][cost + 1] === -1 || dp[nx][ny][cost + 1] > count + 1) {
            const nextValue = { cost: cost + 1, x: nx, y: ny, count: count + 1 };
            fillDp(nextValue);
            q.push(nextValue);
          }
        }
      }
    }
  }
}

function fillDp({ x, y, cost, count }) {
  for (let i = cost; i <= K; i++) {
    dp[x][y][i] = dp[x][y][i] === -1 ? count : Math.min(dp[x][y][i], count);
  }
}
fillDp({ x: 0, y: 0, cost: 0, count: 1 });

bfs();

let answer = Number.MAX_SAFE_INTEGER;
for (let i = 0; i <= K; i++) {
  if (dp[N - 1][M - 1][i] !== -1) answer = Math.min(answer, dp[N - 1][M - 1][i]);
}

console.log(answer === Number.MAX_SAFE_INTEGER ? -1 : answer);
