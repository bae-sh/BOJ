const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input[0];
const arr = new Array(N + 1).fill(0);

const q = [];
q.push([N, 1]);
while (q.length !== 0) {
  const [cur, win] = q.pop();
  arr[cur] = win;
  if (cur - 3 > 0 && arr[cur - 3] === 0) {
    q.push([cur - 3, -win]);
  }
  if (cur - 1 > 0 && arr[cur - 1] === 0) {
    q.push([cur - 1, -win]);
  }
}

if (arr[1] === 1) {
  console.log('SK');
} else {
  console.log('CY');
}
