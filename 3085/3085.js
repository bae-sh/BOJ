const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input[0];
const field = new Array(N);

let ans = 0;

const dx = [0, 1];
const dy = [1, 0];

for (let i = 1; i <= N; i++) {
  const temp = input[i].split('');
  field[i - 1] = temp;
}

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    for (let k = 0; k < 2; k++) {
      const nx = i + dx[k];
      const ny = j + dy[k];

      if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (field[i][j] !== field[nx][ny]) {
          [field[i][j], field[nx][ny]] = [field[nx][ny], field[i][j]];
          checkCandy();
          [field[i][j], field[nx][ny]] = [field[nx][ny], field[i][j]];
        }
      }
    }
  }
}

function checkCandy() {
  for (let i = 0; i < N; i++) {
    let temp = 1;
    for (let j = 1; j < N; j++) {
      if (field[i][j] === field[i][j - 1]) {
        temp += 1;
      } else {
        ans = Math.max(ans, temp);
        temp = 1;
      }
    }
    ans = Math.max(ans, temp);
  }

  for (let i = 0; i < N; i++) {
    let temp = 1;
    for (let j = 1; j < N; j++) {
      if (field[j][i] === field[j - 1][i]) {
        temp += 1;
      } else {
        ans = Math.max(ans, temp);
        temp = 1;
      }
    }
    ans = Math.max(ans, temp);
  }
}

console.log(ans);
