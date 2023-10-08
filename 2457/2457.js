const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let idx = 0;
const N = +input[idx++];
const flowers = [];
const days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30];

for (let i = 0; i < N; i++) {
  let [a, b, c, d] = input[idx++].split(' ').map(Number);
  let sSum = sumDays(a) + b;
  let eSum = sumDays(c) + d;

  flowers.push({ sSum, eSum });
}
flowers.sort((a, b) => {
  if (a.sSum === b.sSum) return b.eSum - a.eSum;
  return a.sSum - b.sSum;
});

function go() {
  let pivot = sumDays(3) + 1;
  let endValue = sumDays(11) + 30;
  let maxRight = -1;
  let count = 0;
  for (let i = 0; i < N; i++) {
    const { sSum, eSum } = flowers[i];
    if (sSum <= pivot) {
      maxRight = Math.max(maxRight, eSum);
      if (maxRight > endValue) {
        return count + 1;
      }
    } else {
      if (maxRight === -1) return 0;
      pivot = maxRight;
      maxRight = -1;
      count += 1;
      i--;
    }
  }
  return 0;
}

function sumDays(m) {
  let sum = 0;
  for (let i = 0; i < m; i++) {
    sum += days[i];
  }
  return sum;
}

console.log(go());
