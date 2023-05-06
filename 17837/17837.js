const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, K] = input.shift().split(' ').map(Number);
const field = []; // 0 흰색 | 1 빨강 | 2 파랑
const mal = new Array(K + 1);
const malField = Array.from({ length: N }, () => Array.from({ length: N }, () => new Array()));
const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

let answer = 0;

let isDone = false;

for (let i = 0; i < N; i++) {
  const temp = input.shift().split(' ').map(Number);
  field.push(temp);
}

for (let i = 0; i < K; i++) {
  const [x, y, way] = input.shift().split(' ').map(Number);
  mal[i + 1] = { x: x - 1, y: y - 1, way: way - 1 };
  malField[x - 1][y - 1].push(i + 1);
}

function checkDone(x, y) {
  if (malField[x][y].length >= 4) isDone = true;
}
function reverseWay(way) {
  switch (way) {
    case 0:
      return 1;
    case 1:
      return 0;
    case 2:
      return 3;
    case 3:
      return 2;
  }
}

function checkField({ count, index }) {
  const { x, y, way } = mal[index];
  const nx = x + dx[way];
  const ny = y + dy[way];
  const arrayIndex = malField[x][y].indexOf(index);
  const newArray = malField[x][y].slice(arrayIndex);

  if (0 <= nx && nx < N && 0 <= ny && ny < N) {
    if (field[nx][ny] === 0) {
      //흰색
      malField[nx][ny] = [...malField[nx][ny], ...newArray];
      newArray.forEach(index => {
        mal[index] = { x: nx, y: ny, way: mal[index].way };
      });
      malField[x][y].splice(arrayIndex);
    } else if (field[nx][ny] === 1) {
      //빨강
      malField[nx][ny] = [...malField[nx][ny], ...newArray.reverse()];
      newArray.forEach(index => {
        mal[index] = { x: nx, y: ny, way: mal[index].way };
      });
      malField[x][y].splice(arrayIndex);
    } else {
      //파랑
      if (count === 0) {
        mal[index].way = reverseWay(way);
        checkField({ count: count + 1, index });
      }
    }
    checkDone(nx, ny);
  } else {
    //장 외 파랑
    if (count === 0) {
      mal[index].way = reverseWay(way);
      checkField({ count: count + 1, index });
    }
  }
}
function malMove() {
  for (let i = 1; i <= K; i++) {
    checkField({ count: 0, index: i });
    if (isDone) return;
  }
}
function start() {
  while (answer < 1000) {
    malMove();
    answer += 1;
    if (isDone) {
      return answer;
    }
  }
  return -1;
}

console.log(start());
