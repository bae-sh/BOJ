const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const likeStd = {};
const order = [];
const field = Array.from({ length: N }, () => new Array(N).fill(0));

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

let ans = 0;

for (let i = 1; i <= N * N; i++) {
  const [num, ...arr] = input[i].split(' ').map(Number);
  order.push(num);
  likeStd[num] = arr;
}
order.forEach(student => {
  let [likeCnt, emptyCnt, x, y] = [-1, -1, -1, -1];
  const curNum = student;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (field[i][j] !== 0) continue;

      const { likeCheck, emptyCheck } = bfs(i, j, curNum);
      if (likeCheck > likeCnt) {
        [likeCnt, emptyCnt, x, y] = [likeCheck, emptyCheck, i, j];
      } else if (likeCheck === likeCnt && emptyCheck > emptyCnt) {
        [likeCnt, emptyCnt, x, y] = [likeCheck, emptyCheck, i, j];
      }
    }
  }

  field[x][y] = curNum;
});

checkLikeStd();
console.log(ans);

function bfs(i, j, curNum) {
  let [likeCheck, emptyCheck] = [0, 0];

  for (let k = 0; k < 4; k++) {
    let nx = i + dx[k];
    let ny = j + dy[k];

    if (0 <= nx && nx < N && 0 <= ny && ny < N) {
      const nextNum = field[nx][ny];
      if (likeStd[curNum].includes(nextNum)) {
        likeCheck += 1;
      } else if (nextNum === 0) {
        emptyCheck += 1;
      }
    }
  }
  return { likeCheck, emptyCheck };
}

function checkLikeStd() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      const { likeCheck } = bfs(i, j, field[i][j]);
      if (likeCheck > 0) ans += 10 ** (likeCheck - 1);
    }
  }
}
