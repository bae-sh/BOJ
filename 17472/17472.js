// 1. bfs 영역 구분
// 2. 놓을수 있는 다리 놓기
// 3. 다리 길이가 긴 것부터 차례대로 제거 후 다른 도시로 이동가능 판별

const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M] = input[0].split(' ').map(Number);
const field = new Array(N);
const MAX_LEN = 987654321;
let areaCnt = 0;

const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

let ans = 0;

for (let i = 0; i < N; i++) {
  field[i] = input[i + 1].split(' ').map(num => -1 * Number(num));
}

putArea();
const bridge = Array.from({ length: areaCnt + 1 }, () => new Array(areaCnt + 1).fill(MAX_LEN));

checkArea();
if (!bfsArea(1)) {
  ans = -1;
} else {
  removeBridge();
}

console.log(ans);

function removeBridge() {
  const orderBridge = [];
  for (let i = 1; i <= areaCnt; i++) {
    for (let j = i + 1; j <= areaCnt; j++) {
      if (bridge[i][j] !== MAX_LEN) {
        orderBridge.push({ x: i, y: j, len: bridge[i][j] });
      }
    }
  }
  orderBridge.sort((a, b) => {
    return b.len - a.len;
  });
  orderBridge.forEach(({ x, y, len }) => {
    bridge[x][y] = MAX_LEN;
    bridge[y][x] = MAX_LEN;
    if (!bfsArea(x)) {
      bridge[x][y] = len;
      bridge[y][x] = len;
      ans += len;
    }
  });
}

function bfsArea(start) {
  const q = [start];
  const visited = new Array(areaCnt + 1).fill(false);
  visited[start] = true;

  while (q.length !== 0) {
    const cur = q.shift();
    for (let i = 1; i <= areaCnt; i++) {
      const nextValue = bridge[cur][i];

      if (nextValue !== MAX_LEN && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }

  for (let i = 1; i <= areaCnt; i++) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

function checkArea() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      const area = field[i][j];

      if (area !== 0) {
        putBridge(i, j, area);
      }
    }
  }
}

function putBridge(x, y, area) {
  for (let i = 0; i < 2; i++) {
    let len = 0;

    while (true) {
      const nx = x + dx[i] * (len + 1);
      const ny = y + dy[i] * (len + 1);
      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        const nextArea = field[nx][ny];

        if (nextArea === 0) {
          len += 1;
        } else if (nextArea !== area) {
          if (len < 2) break;
          const minLen = Math.min(len, bridge[area][nextArea]);
          bridge[area][nextArea] = minLen;
          bridge[nextArea][area] = minLen;
          break;
        } else {
          break;
        }
      } else {
        break;
      }
    }
  }
}

function putArea() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (field[i][j] === -1) {
        areaCnt += 1;
        bfs(i, j);
      }
    }
  }
}

function bfs(i, j) {
  const q = [[i, j]];
  field[i][j] = areaCnt;

  while (q.length !== 0) {
    const [x, y] = q.shift();

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (field[nx][ny] === -1) {
          field[nx][ny] = areaCnt;
          q.push([nx, ny]);
        }
      }
    }
  }
}
