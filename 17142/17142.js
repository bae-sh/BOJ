const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];
let ans = Number.MAX_SAFE_INTEGER;

const field = [];
const virusPos = [];
const [N, M] = input.shift().split(' ').map(Number);

for (let i = 0; i < N; i++) {
  const temp = input.shift().split(' ').map(Number);
  field.push(temp);

  temp.forEach((num, index) => {
    if (num === 2) {
      virusPos.push({ x: i, y: index });
    }
  });
}

function bfs(viruses) {
  const gameField = [];
  const curViruses = [];
  let count = 0;

  for (let i = 0; i < N; i++) {
    gameField.push([...field[i]]);
    gameField[i].forEach((num, index) => {
      if (num === 0) count += 1;
      if (num === 2) gameField[i][index] = -1;
    });
  }
  if (count === 0) ans = 0;
  viruses.forEach(({ x, y }) => {
    curViruses.push({ x, y, curCount: 0 });
    gameField[x][y] = -2;
  });
  while (curViruses.length !== 0) {
    const { x, y, curCount } = curViruses.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (gameField[nx][ny] === 0) {
          gameField[nx][ny] = curCount + 1;
          count -= 1;
          curViruses.push({ x: nx, y: ny, curCount: curCount + 1 });

          if (count === 0) {
            ans = Math.min(ans, curCount + 1);
            return;
          }
        } else if (gameField[nx][ny] === -1) {
          gameField[nx][ny] = curCount + 1;
          curViruses.push({ x: nx, y: ny, curCount: curCount + 1 });
        }
      }
    }
  }
}

function playGame(viruses, curIndex) {
  if (viruses.length === M) {
    bfs(viruses);
    return;
  }

  for (let i = curIndex; i < virusPos.length; i++) {
    playGame([...viruses, virusPos[i]], i + 1);
  }
}

playGame([], 0);

console.log(ans === Number.MAX_SAFE_INTEGER ? '-1' : ans);
