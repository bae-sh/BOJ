const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const n = +input[0];
let inputIndex = 1;
const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];
let w, h;

function checkPos(field) {
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < w; j++) {
      if (field[i][j] === '@') return [i, j];
    }
  }
}
function moveFire(field) {
  const list = [];
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < w; j++) {
      if (field[i][j] === '*') {
        list.push({ x: i, y: j });
        field[i][j] = 0;
      }
    }
  }
  while (list.length !== 0) {
    const { x, y } = list.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        if (field[nx][ny] === '.') {
          field[nx][ny] = field[x][y] + 1;
          list.push({ x: nx, y: ny });
        }
      }
    }
  }
}
function go(field) {
  let [x, y] = checkPos(field);
  const q = [{ x, y, curCount: 1 }];
  const visited = Array.from({ length: h }, () => new Array(w).fill(false));
  visited[x][y] = true;
  moveFire(field);

  while (q.length !== 0) {
    const { x, y, curCount } = q.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < h && 0 <= ny && ny < w) {
        if ((field[nx][ny] === '.' || field[nx][ny] > curCount) && visited[nx][ny] === false) {
          q.push({ x: nx, y: ny, curCount: curCount + 1 });
          visited[nx][ny] = true;
        }
      } else {
        return curCount;
      }
    }
  }
  return -1;
}
function init() {
  let str = '';
  for (let i = 0; i < n; i++) {
    [w, h] = input[inputIndex].split(' ').map(Number);
    const field = [];
    inputIndex += 1;
    for (let j = 0; j < h; j++) {
      const arr = input[inputIndex].split('');
      field.push(arr);
      inputIndex += 1;
    }

    const answer = go(field);

    if (answer === -1) str += 'IMPOSSIBLE\n';
    else str += answer + '\n';
  }
  console.log(str);
}

init();
