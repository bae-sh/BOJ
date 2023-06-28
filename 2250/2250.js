const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();

const arr = Array.from({ length: N + 1 }, () => new Array());
const arrReverse = Array.from({ length: N + 1 }, () => new Array());
const levelArr = Array.from({ length: N + 1 }, () => new Array());
for (let i = 0; i < N; i++) {
  const [a, b, c] = input.shift().split(' ').map(Number);
  arr[a].push(b, c);
  if (b !== -1) arrReverse[b].push(a);
  if (c !== -1) arrReverse[c].push(a);
}

let count = 1;
let [ansLevel, ansWidth] = [0, 0];

function findParent(num) {
  if (arrReverse[num].length === 0) return num;
  return findParent(arrReverse[num]);
}
function check(num, level) {
  const [l, r] = arr[num];
  if (l !== -1) {
    check(l, level + 1);
  }
  levelArr[level].push(count);
  count += 1;

  if (r !== -1) {
    check(r, level + 1);
  }
  return;
}

const start = findParent(1);

check(start, 1);

for (let i = 1; i < N + 1; i++) {
  if (levelArr[i].length === 0) break;

  const width = levelArr[i][levelArr[i].length - 1] - levelArr[i][0] + 1;
  if (width > ansWidth) {
    [ansLevel, ansWidth] = [i, width];
  }
}

console.log(ansLevel, ansWidth);
