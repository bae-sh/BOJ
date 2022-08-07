const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const MOD = 1e9 + 7;
const ADD_X = 200001;
const MAX_X = 400001;
const N = +input[0];
const cor = [];
let buffer = [];
let ans = 0;
const tree = new Array(1600001).fill(0);

for (let i = 0; i < N; i++) {
  const [x, y] = input[i + 1].split(' ').map(Number);
  cor.push({ x: x + ADD_X, y });
}

cor.sort((a, b) => {
  if (a.y !== b.y) return b.y - a.y;
  else return a.x - b.x;
});
cor.forEach(({ x, y }) => {
  clearBuffer({ x, y });

  const left = search(1, 0, MAX_X, 0, x - 1);
  const right = search(1, 0, MAX_X, x + 1, MAX_X);
  ans += (left * right) % MOD;
});

console.log(ans % MOD);

function setTree(index, start, end, x) {
  const mid = Math.floor((start + end) / 2);

  if (start === end) {
    return (tree[index] += 1);
  }
  if (x <= mid) {
    setTree(index * 2, start, mid, x);
  } else {
    setTree(index * 2 + 1, mid + 1, end, x);
  }
  tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

function search(index, start, end, left, right) {
  const mid = Math.floor((start + end) / 2);

  if (left > end || right < start) return 0;
  if (left <= start && end <= right) return tree[index];

  return (
    search(index * 2, start, mid, left, right) + search(index * 2 + 1, mid + 1, end, left, right)
  );
}

function clearBuffer({ x, y }) {
  if (buffer.length === 0) {
    buffer.push({ x, y });
  } else {
    if (buffer[0].y === y) {
      buffer.push({ x, y });
    } else {
      buffer.forEach(({ x }) => {
        setTree(1, 0, MAX_X, x);
      });
      buffer = [{ x, y }];
    }
  }
}
