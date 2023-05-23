const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const query = [];
let score = 0;

for (let i = 1; i <= N; i++) {
  const [t, x, y] = input[i].split(' ').map(Number);
  query.push({ t, x, y });
}

const green = Array.from(new Array(6), () => new Array(4).fill(0));
const blue = Array.from(new Array(6), () => new Array(4).fill(0));

playGame();
let cnt = 0;
cnt += countTile(green);
cnt += countTile(blue);

console.log(`${score}\n${cnt}`);

function playGame() {
  for (let i = 1; i <= N; i++) {
    const { t, x, y } = query.shift();
    let greenTile = putTile(t, x, y);
    let blueTile = putTile(t === 1 ? 1 : t === 2 ? 3 : 2, y, x);
    moveTile(greenTile, green);
    moveTile(blueTile, blue);

    score += getScore(green);
    score += getScore(blue);

    emptyPaleArea(green);
    emptyPaleArea(blue);
  }
}

function putTile(t, r, c) {
  let tilePos;
  if (t === 1) tilePos = [[1, c]];
  else if (t === 2)
    tilePos = [
      [1, c],
      [1, c + 1],
    ];
  else
    tilePos = [
      [0, c],
      [1, c],
    ];
  return tilePos;
}

function moveTile(tile, board) {
  let cur = tile;
  let canMove = true;

  while (canMove) {
    let next = [];
    for (let [r, c] of cur) {
      let [r2, c2] = [r + 1, c];
      if (r2 > 5 || board[r2][c2] === 1) {
        canMove = false;
      }
      next.push([r2, c2]);
    }
    if (canMove) {
      cur = next;
    }
  }
  for (let [r, c] of cur) {
    board[r][c] = 1;
  }
}

function getScore(board) {
  let score = 0;
  for (let r = 0; r <= 5; r++) {
    if (board[r].reduce((prev, cur) => prev + cur, 0) === 4) {
      score += 1;
      for (let i = r; i > 0; i--) {
        board[i] = board[i - 1];
      }
      board[0] = [0, 0, 0, 0];
    }
  }
  return score;
}

function emptyPaleArea(board) {
  let cnt = 0;

  for (let r of [0, 1]) {
    if (board[r].reduce((prev, cur) => prev + cur, 0) > 0) cnt++;
  }
  for (let i = 0; i < cnt; i++) {
    board.pop();
    board.unshift([0, 0, 0, 0]);
  }
}

function countTile(board) {
  let cnt = 0;
  for (let line of board) {
    for (let val of line) {
      if (val == 1) cnt++;
    }
  }
  return cnt;
}
