const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [-1, -1, 0, 1, 1, 1, 0, -1];
const dy = [0, -1, -1, -1, 0, 1, 1, 1];
const N = 4;

const field = Array.from({ length: N }, () => new Array(N).fill({ num: 0, way: 0 }));
let ans = 0;

for (let i = 0; i < N; i++) {
  const arr = input[i].split(' ').map(Number);
  for (let j = 0; j < N; j++) {
    const [num, way] = [arr[j * 2], arr[2 * j + 1]];
    field[i][j] = { num: num, way: way - 1 };
  }
}

game(field[0][0].num, field, 0, 0, field[0][0].way);
console.log(ans);

function game(eat, space, sx, sy, sway) {
  let ate = false;
  const newSpace = space.map(item =>
    item.map(obj => {
      return { ...obj };
    }),
  );

  newSpace[sx][sy] = { num: -1, way: sway };
  rotateSpace(newSpace);
  for (let i = 1; i < N; i++) {
    const nx = sx + dx[sway] * i;
    const ny = sy + dy[sway] * i;

    if (0 <= nx && nx < N && 0 <= ny && ny < N) {
      const feed = newSpace[nx][ny].num;
      const newWay = newSpace[nx][ny].way;
      newSpace[sx][sy] = { num: 0, way: 0 };
      if (feed > 0) {
        ate = true;
        game(eat + feed, newSpace, nx, ny, newWay);
      }
      newSpace[sx][sy] = { num: -1, way: sway };
    }
  }

  if (!ate) {
    ans = Math.max(ans, eat);
  }
}

function rotateSpace(newSpace) {
  const order = getOrder(newSpace);

  for (let i = 1; i <= 16; i++) {
    const { x, y } = order[i];

    if (x !== -1 && y !== -1) {
      const way = newSpace[x][y].way;

      for (let j = 0; j < 8; j++) {
        const nway = (way + j) % 8;
        const nx = x + dx[nway];
        const ny = y + dy[nway];
        newSpace[x][y].way = nway;

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
          const nNum = newSpace[nx][ny].num;
          if (nNum >= 0) {
            // newSpace[x][y].way = nway;
            [newSpace[x][y], newSpace[nx][ny]] = [newSpace[nx][ny], newSpace[x][y]];
            order[nNum] = { x, y };
            break;
          }
        }
      }
    }
  }
}

function getOrder(space) {
  const arr = new Array(17).fill({ x: -1, y: -1 });

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      const num = space[i][j].num;
      if (num > 0) {
        arr[num] = { x: i, y: j };
      }
    }
  }
  return arr;
}
