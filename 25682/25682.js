const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M, K] = input[0].split(' ').map(Number);
const color = ['B', 'W'];
const board = [];
let answer = Number.MAX_SAFE_INTEGER;

function gameStart() {
  const dp = Array.from({ length: N + 1 }, () => new Array(M + 1).fill(0));
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j];

      const order = (i + j) % 2;
      if (board[i][j] !== color[order]) {
        dp[i + 1][j + 1] += 1;
      }
    }
  }

  for (let i = K; i <= N; i++) {
    for (let j = K; j <= M; j++) {
      answer = Math.min(answer, dp[i][j] - dp[i][j - K] - dp[i - K][j] + dp[i - K][j - K]);
    }
  }
}

function init() {
  for (let i = 1; i <= N; i++) {
    board.push(input[i].split(''));
  }

  gameStart();
  [color[0], color[1]] = [color[1], color[0]];
  gameStart();
}

init();

console.log(answer);
