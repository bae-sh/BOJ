const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const field = new Array(N);

let answer = 987654321;

for (let i = 1; i <= N; i++) {
  const arr = input[i].split(' ').map(Number);
  field[i - 1] = arr;
}

checkField(0, 0);
console.log(answer);

function checkField(visitCnt, filpCnt) {
  if (visitCnt >= 2 * N) {
    checkAns(filpCnt);
    return;
  }
  if (visitCnt < N) {
    flipRowCoin(visitCnt);
    checkField(visitCnt + 1, filpCnt + 1);
    flipRowCoin(visitCnt);
    checkField(visitCnt + 1, filpCnt);
  } else {
    flipColCoin(visitCnt - N);
    checkField(visitCnt + 1, filpCnt + 1);
    flipColCoin(visitCnt - N);
    checkField(visitCnt + 1, filpCnt);
  }
}

function flipRowCoin(x) {
  for (let i = 0; i < N; i++) {
    field[x][i] ^= 1;
  }
}

function flipColCoin(y) {
  for (let i = 0; i < N; i++) {
    field[i][y] ^= 1;
  }
}

function checkAns(filpCnt) {
  let temp = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      temp += field[i][j];
    }
  }
  temp = Math.min(temp, N * N - temp);
  answer = Math.min(answer, filpCnt + temp);
}
