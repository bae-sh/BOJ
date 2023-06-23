const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const T = +input.shift();

for (let i = 0; i < T; i++) {
  console.log(cal());
}

function cal() {
  const [x1, y1, r1, x2, y2, r2] = input.shift().split(' ').map(Number);

  const distance = (x1 - x2) ** 2 + (y1 - y2) ** 2;
  const center2 = (r1 + r2) ** 2;
  const center3 = (r1 - r2) ** 2;

  if (r1 === 0) return 1;
  if (distance === 0 && r1 === r2) return -1;
  if (distance < center2 && center3 < distance) return 2;
  if (distance === center2 || distance === center3) return 1;
  return 0;
}
