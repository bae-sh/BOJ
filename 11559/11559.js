const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const arr = input.map(line => line.split(''));

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

let ans = 0;

function moveDown() {
  for (let i = 0; i < 6; i++) {
    const items = [];

    for (let j = 0; j < 12; j++) {
      if (arr[j][i] !== '.') {
        items.push(arr[j][i]);
      }
    }

    for (let j = 11; j >= 0; j--) {
      let item = '.';

      if (items.length !== 0) {
        item = items.pop();
      }
      arr[j][i] = item;
    }
  }
}

function bfs(x, y, visited) {
  const visitCor = [[x, y]];
  const q = [[x, y]];
  visited[x][y] = true;

  while (q.length !== 0) {
    const [x, y] = q.shift();
    const item = arr[x][y];

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (0 <= nx && nx < 12 && 0 <= ny && ny < 6) {
        if (!visited[nx][ny] && arr[nx][ny] === item) {
          visited[nx][ny] = true;
          visitCor.push([nx, ny]);
          q.push([nx, ny]);
        }
      }
    }
  }

  if (visitCor.length >= 4) {
    visitCor.map(cor => {
      const [x, y] = cor;
      arr[x][y] = '.';
    });
    return true;
  }
  return false;
}

function bomb() {
  const visited = Array.from({ length: 12 }, () => new Array(6).fill(false));
  let isBombed = false;
  for (let i = 0; i < 12; i++) {
    for (let j = 0; j < 6; j++) {
      if (arr[i][j] !== '.' && !visited[i][j]) {
        if (bfs(i, j, visited)) {
          isBombed = true;
        }
      }
    }
  }
  if (isBombed) {
    ans += 1;
    moveDown();
  }
  return isBombed;
}

while (bomb());

console.log(ans);
