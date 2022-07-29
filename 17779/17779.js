const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input[0];
const field = new Array(N + 1);
let ans = 987654321;

for (let i = 1; i <= N; i++) {
  field[i] = [0, ...input[i].split(' ').map(Number)];
}

bruteForce();
console.log(ans);

function checkArea({ x, y, d1, d2, cnt }) {
  const area5 = getArea5({ x, y, d1, d2 });
  for (let r = 1; r <= N; r++) {
    for (let c = 1; c <= N; c++) {
      if (area5[r][c]) {
        cnt[4] += field[r][c];
      } else if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
        cnt[0] += field[r][c];
        // console.log(0, r, c, field[r][c]);
      } else if (1 <= r && r <= x + d2 && y < c && c <= N) {
        cnt[1] += field[r][c];
      } else if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
        cnt[2] += field[r][c];
      } else if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
        cnt[3] += field[r][c];
      } else {
        cnt[4] += field[r][c];
      }
    }
  }
}

function bruteForce() {
  for (let d1 = 1; d1 <= N; d1++) {
    for (let d2 = 1; d2 <= N; d2++) {
      for (let x = 1; x <= N - d1 - d2; x++) {
        for (let y = 1 + d1; y + d2 <= N; y++) {
          const cnt = new Array(5).fill(0);
          checkArea({ x, y, d1, d2, cnt });
          cnt.sort((a, b) => a - b);
          ans = Math.min(ans, cnt[4] - cnt[0]);
        }
      }
    }
  }
}

function getArea5({ x, y, d1, d2 }) {
  const area5 = Array.from({ length: N + 1 }, () => new Array(N + 1).fill(0));

  for (let i = 0; i <= d1; i++) {
    area5[x + i][y - i] = 1;
    area5[x + d2 + i][y + d2 - i] = 1;
  }
  for (let i = 0; i <= d2; i++) {
    area5[x + i][y + i] = 1;
    area5[x + d1 + i][y - d1 + i] = 1;
  }

  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      if ((i == x && j == y) || (i == x + d1 + d2 && j == y - d1 + d2)) break;
      if (area5[i][j - 1] == 1 && area5[i][j] == 1) break;
      if (area5[i][j - 1] == 1 && area5[i][j] == 0) area5[i][j] = 1;
    }
  }

  return area5;
}
