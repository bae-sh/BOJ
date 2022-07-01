const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M, H] = input[0].split(' ').map(Number);
const ladder = Array.from({ length: H + 1 }, () => new Array(N + 1).fill(0));
let ans = 4;

for (let i = 1; i < M + 1; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  putLadder(a, b);
}

function putLadder(a, b) {
  ladder[a][b] = 1;
  ladder[a][b + 1] = -1;
}

function backLadder(a, b) {
  ladder[a][b] = 0;
  ladder[a][b + 1] = 0;
}

function startGame() {
  for (let i = 1; i <= N; i++) {
    let number = i;
    for (let j = 1; j <= H; j++) {
      number += ladder[j][number];
    }
    if (number !== i) {
      return false;
    }
  }
  return true;
}

function solve(count) {
  if (startGame()) {
    ans = Math.min(ans, count);
    return;
  }
  if (count === 3) return;
  for (let i = 1; i <= H; i++) {
    for (let j = 1; j < N; j++) {
      if (ladder[i][j] === 0 && ladder[i][j + 1] === 0) {
        putLadder(i, j);
        solve(count + 1);
        backLadder(i, j);
      }
    }
  }
}
solve(0);
if (ans === 4) {
  console.log(-1);
} else {
  console.log(ans);
}
