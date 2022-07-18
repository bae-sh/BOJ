const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M, K] = input[0].split(' ').map(Number);
let arr = [];
const querys = [];
const visited = new Array(K).fill(false);
let ans = 987654321;

for (let i = 1; i <= N; i++) {
  const row = input[i].split(' ').map(Number);
  arr.push(row);
}

for (let i = 0; i < K; i++) {
  const query = input[N + 1 + i].split(' ').map(Number);

  querys.push(query);
}

function rotate(sx, sy, ex, ey) {
  let number = arr[sx][sy];
  for (let i = sy + 1; i <= ey; i++) {
    [number, arr[sx][i]] = [arr[sx][i], number];
  }
  for (let i = sx + 1; i <= ex; i++) {
    [number, arr[i][ey]] = [arr[i][ey], number];
  }
  for (let i = ey - 1; i >= sy; i--) {
    [number, arr[ex][i]] = [arr[ex][i], number];
  }
  for (let i = ex - 1; i >= sx; i--) {
    [number, arr[i][sy]] = [arr[i][sy], number];
  }
}

function minRow() {
  let minValue = 987654321;
  for (let i = 0; i < N; i++) {
    let curValue = 0;
    for (let j = 0; j < M; j++) {
      curValue += arr[i][j];
    }
    minValue = Math.min(minValue, curValue);
  }
  return minValue;
}

function permutation(count) {
  if (count === K) {
    ans = Math.min(ans, minRow());
    return;
  }
  for (let i = 0; i < K; i++) {
    if (!visited[i]) {
      visited[i] = true;
      const prevArr = arr.map(row => [...row]);
      const [r, c, s] = querys[i];

      for (let j = 0; j < N; j++) {
        const [sx, sy, ex, ey] = [r - s - 1 + j, c - s - 1 + j, r + s - 1 - j, c + s - 1 - j];

        if (sx >= ex || sy >= ey) break;
        rotate(sx, sy, ex, ey);
      }
      permutation(count + 1);
      arr = prevArr;
      visited[i] = false;
    }
  }
}
permutation(0);
console.log(ans);
