const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M, T] = input[0].split(' ').map(Number);
let circle = [];

for (let i = 0; i < N; i++) {
  const arr = input[i + 1].split(' ').map(Number);
  circle.push(arr);
}

for (let i = N + 1; i < N + 1 + T; i++) {
  const [x, d, k] = input[i].split(' ').map(Number);
  rotateCircle(x, d, k);
}
console.log(totalCircle());

function rotateCircle(x, d, k) {
  if (d === 0) {
    for (let i = x - 1; i < N; i += x) {
      const arr = circle[i].splice(M - k, k);
      circle[i] = [...arr, ...circle[i]];
    }
  } else {
    for (let i = x - 1; i < N; i += x) {
      const arr = circle[i].splice(0, k);
      circle[i] = [...circle[i], ...arr];
    }
  }
  removeNumber();
}

function removeNumber() {
  let newCircle = circle.map(arr => [...arr]);
  let isRemove = false;
  let avg = 0;
  let cnt = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      let next = (j + 1) % M;

      if (circle[i][j] !== 0) {
        avg += circle[i][j];
        cnt += 1;
      }

      if (circle[i][j] === circle[i][next] && circle[i][j] !== 0) {
        [newCircle[i][j], newCircle[i][next]] = [0, 0];
        isRemove = true;
      }
      next = i + 1;
      if (next < N) {
        if (circle[i][j] === circle[next][j] && circle[i][j] !== 0) {
          [newCircle[i][j], newCircle[next][j]] = [0, 0];
          isRemove = true;
        }
      }
    }
  }

  if (!isRemove) {
    avg = avg / cnt;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        if (newCircle[i][j] !== 0) {
          if (newCircle[i][j] > avg) {
            newCircle[i][j] -= 1;
          } else if (newCircle[i][j] < avg) {
            newCircle[i][j] += 1;
          }
        }
      }
    }
  }
  circle = newCircle;
}

function totalCircle() {
  let total = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      total += circle[i][j];
    }
  }
  return total;
}
