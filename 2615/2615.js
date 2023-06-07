const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const dx = [-1, 0, 1, 1];
const dy = [1, 1, 1, 0];
let ans = 0;
let [X, Y] = [0, 0];
const field = [];

field.push(new Array(21).fill(0));

for (let i = 0; i < 19; i++) {
  const temp = input.shift().split(' ').map(Number);
  field.push([0, ...temp, 0]);
}
field.push(new Array(21).fill(0));

function checkPos(x, y) {
  for (let k = 0; k < 4; k++) {
    const [revX, revY] = [x - dx[k], y - dy[k]];
    if (field[revX][revY] === field[x][y]) continue;

    let count = 0;

    for (let j = 1; j <= 5; j++) {
      const nx = x + j * dx[k];
      const ny = y + j * dy[k];
      if (0 < nx && nx < 20 && 0 < ny && ny < 20) {
        if (field[nx][ny] === field[x][y]) {
          count += 1;
          if (j === 5) count *= -1;
        }
      }
    }

    if (count === 4) {
      ans = field[x][y];
      [X, Y] = [x, y];
      return;
    }
  }
}

function playGame() {
  for (let i = 1; i < 20; i++) {
    for (let j = 1; j < 20; j++) {
      if (field[i][j] === 0) continue;
      checkPos(i, j);
      if (ans !== 0) return;
    }
  }
}

playGame();

console.log(ans);

if (ans !== 0) {
  console.log(X, Y);
}
