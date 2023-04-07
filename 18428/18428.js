const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const field = [];
const teacherPos = [];
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
let answer = 'NO';

for (let i = 1; i <= N; i++) {
  const arr = input[i].split(' ');
  arr.forEach((value, index) => {
    if (value === 'T') {
      teacherPos.push({ x: i - 1, y: index });
    }
  });
  field.push(arr);
}

function bruteForce(x, y, count) {
  if (count >= 3) {
    check();
    return;
  }
  for (let j = y; j < N; j++) {
    if (field[x][j] === 'X') {
      field[x][j] = 'O';
      bruteForce(x, j + 1, count + 1);
      field[x][j] = 'X';
    }
  }
  for (let i = x + 1; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (field[i][j] === 'X') {
        field[i][j] = 'O';
        bruteForce(i, j + 1, count + 1);
        field[i][j] = 'X';
      }
    }
  }
}

function check() {
  let meetStudent = false;
  teacherPos.forEach(({ x, y }) => {
    for (let i = 0; i < 4; i++) {
      for (let j = 1; ; j++) {
        const nx = x + dx[i] * j;
        const ny = y + dy[i] * j;

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
          if (field[nx][ny] === 'T' || field[nx][ny] === 'O') break;
          if (field[nx][ny] === 'S') {
            meetStudent = true;
            break;
          }
        } else {
          break;
        }
      }
    }
  });

  if (!meetStudent) {
    answer = 'YES';
  }
}
bruteForce(0, 0, 0);
console.log(answer);
