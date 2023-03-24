const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const lines = [];
const arr = [];

let answer = 0;

for (let i = 0; i < N; i++) {
  const [x, y] = input.shift().split(' ').map(Number);
  lines.push({ x, y });
}

lines.sort((a, b) => {
  if (a.x === b.x) return a.y - b.y;
  return a.x - b.x;
});

let [l, r] = [lines[0].x, lines[0].y];
lines.forEach(({ x, y }) => {
  if (l <= x && x <= r) {
    r = Math.max(r, y);
  } else {
    answer += r - l;
    [l, r] = [x, y];
  }
});
answer += r - l;

console.log(answer);
