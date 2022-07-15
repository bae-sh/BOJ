const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M, D] = input[0].split(' ').map(Number);
const originField = [];
let field = [];
const archerPos = [];
let killEnermy = 0;
let ans = 0;
for (let i = 1; i <= N; i++) {
  const arr = input[i].split(' ').map(Number);
  originField.push(arr);
}
moveArcher(0);

function moveArcher(position) {
  if (archerPos.length === 3) {
    killEnermy = 0;
    field = originField.map(row => [...row]);
    gameStart();
    ans = Math.max(ans, killEnermy);
  } else {
    for (let i = position; i < M; i++) {
      archerPos.push(i);
      moveArcher(i + 1);
      archerPos.pop();
    }
  }
}

function gameStart() {
  for (let i = 0; i < N; i++) {
    const enermyPos = [];
    nextState(enermyPos);
    moveField(enermyPos);
  }
}

function nextState(enermyPos) {
  archerPos.forEach(c => {
    findEnemy(N, c, enermyPos);
  });
}

function findEnemy(r, c, enermyPos) {
  const q = [[r - 1, c, 1]];
  const dx = [0, -1, 0];
  const dy = [-1, 0, 1];
  while (q.length !== 0) {
    const [x, y, count] = q.shift();
    if (field[x][y]) {
      enermyPos.push([x, y]);
      return;
    }
    if (count + 1 <= D) {
      for (let i = 0; i < 3; i++) {
        const nx = x + dx[i];
        const ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
          if (field[nx][ny]) {
            enermyPos.push([nx, ny]);
            return;
          } else {
            q.push([nx, ny, count + 1]);
          }
        }
      }
    }
  }
}
function moveField(enermyPos) {
  enermyPos.forEach(([x, y]) => {
    if (field[x][y]) {
      field[x][y] = 0;
      killEnermy += 1;
    }
  });
  const newRow = new Array(M).fill(0);
  field = [newRow, ...field];
}
console.log(ans);
