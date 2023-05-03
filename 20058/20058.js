//배열 복사하는법
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, Q] = input.shift().split(' ').map(Number);
const arr = Array.from({ length: 2 ** N }, () => new Array());

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

let size = 0;

for (let i = 0; i < 2 ** N; i++) {
  arr[i] = input.shift().split(' ').map(Number);
}

const query = input.shift().split(' ').map(Number);

function rotateLine(x, y, len) {
  const copyArray = Array.from({ length: len }, () => new Array(len).fill(0));

  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len; j++) {
      copyArray[i][j] = arr[x + i][y + j];
    }
  }

  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len; j++) {
      arr[x + i][y + j] = copyArray[len - 1 - j][i];
    }
  }
}

function arraySum() {
  let sum = 0;
  for (let i = 0; i < 2 ** N; i++) {
    for (let j = 0; j < 2 ** N; j++) {
      sum += arr[i][j];
    }
  }
  return sum;
}

function meltIce() {
  const queue = [];
  for (let i = 0; i < 2 ** N; i++) {
    for (let j = 0; j < 2 ** N; j++) {
      if (arr[i][j] == 0) continue;

      let count = 0;
      for (let k = 0; k < 4; k++) {
        const nx = i + dx[k];
        const ny = j + dy[k];
        if (0 <= nx && nx < 2 ** N && 0 <= ny && ny < 2 ** N) {
          if (arr[nx][ny] > 0) count += 1;
        }
      }
      if (count < 3) {
        queue.push({ x: i, y: j });
      }
    }
  }
  queue.forEach(({ x, y }) => {
    arr[x][y] -= 1;
  });
}

function checkGroup() {
  const visited = Array.from({ length: 2 ** N }, () => new Array(2 ** N).fill(false));
  for (let i = 0; i < 2 ** N; i++) {
    for (let j = 0; j < 2 ** N; j++) {
      if (arr[i][j] > 0 && !visited[i][j]) {
        let count = 1;
        visited[i][j] = true;
        const queue = [{ x: i, y: j }];

        while (queue.length !== 0) {
          const { x, y } = queue.shift();
          for (let k = 0; k < 4; k++) {
            const nx = x + dx[k];
            const ny = y + dy[k];

            if (0 <= nx && nx < 2 ** N && 0 <= ny && ny < 2 ** N) {
              if (arr[nx][ny] > 0 && !visited[nx][ny]) {
                count += 1;
                queue.push({ x: nx, y: ny });
                visited[nx][ny] = true;
              }
            }
          }
        }
        size = Math.max(size, count);
      }
    }
  }
}
for (const len of query) {
  for (let i = 0; i < 2 ** N; i += 2 ** len) {
    for (let j = 0; j < 2 ** N; j += 2 ** len) {
      rotateLine(i, j, 2 ** len);
    }
  }
  meltIce();
}
checkGroup();
console.log(arraySum());
console.log(size);
