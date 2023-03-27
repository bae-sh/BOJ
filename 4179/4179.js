const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];

const [R, C] = input[0].split(' ').map(Number);
const field = [];
const visited = Array.from({ length: R }, () => new Array(C).fill(false));
const curFire = [];

let jx, jy;
let answer = -1;
for (let i = 1; i <= R; i++) {
  const temp = input[i].split('');
  for (let j = 0; j < C; j++) {
    if (temp[j] === 'J') {
      [jx, jy] = [i - 1, j];
      temp[j] = '.';
    } else if (temp[j] === 'F') {
      curFire.push({ x: i - 1, y: j });
      temp[j] = 0;
    }
  }
  field.push(temp);
}

function bfs() {
  const q = [{ x: jx, y: jy, time: 0 }];
  visited[jx][jy] = true;
  while (q.length !== 0) {
    const { x, y, time } = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < R && 0 <= ny && ny < C) {
        if ((time + 1 < field[nx][ny] || field[nx][ny] === '.') && !visited[nx][ny]) {
          q.push({ x: nx, y: ny, time: time + 1 });
          visited[nx][ny] = true;
        }
      } else {
        answer = time + 1;
        return;
      }
    }
  }
}

function moveFire() {
  while (curFire.length !== 0) {
    const { x, y } = curFire.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < R && 0 <= ny && ny < C) {
        if (field[nx][ny] === '.' || field[nx][ny] > field[x][y] + 1) {
          field[nx][ny] = field[x][y] + 1;
          curFire.push({ x: nx, y: ny });
        }
      }
    }
  }
}
moveFire();
bfs();

console.log(answer === -1 ? 'IMPOSSIBLE' : answer);
