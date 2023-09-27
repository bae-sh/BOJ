//정렬 후 투포인터
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let idx = 0;
const NANO = 10_000_000;
while (idx < input.length) {
  const len = +input[idx++] * NANO;
  const size = +input[idx++];

  const q = [];
  for (let i = 0; i < size; i++) {
    q.push(+input[idx++]);
  }
  q.sort((a, b) => a - b);
  twoPointer(q, len);
}

function twoPointer(q, len) {
  let [l, r] = [0, q.length - 1];
  while (l < r) {
    const sum = q[l] + q[r];
    if (sum === len) {
      console.log('yes', q[l], q[r]);
      return;
    }
    if (sum < len) {
      l += 1;
    } else if (sum > len) {
      r -= 1;
    }
  }
  console.log('danger');
}
