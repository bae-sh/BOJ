const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const arr = [];
const [N, K] = input.shift().split(' ').map(Number);
for (let i = 0; i < N; i++) {
  const [c, g, s, b] = input.shift().split(' ').map(Number);
  arr.push({ c, g, s, b });
}

arr.sort((a, b) => {
  if (a.g === b.g) {
    if (a.s === b.s) {
      return b.b - a.b;
    }
    return b.s - a.s;
  }
  return b.g - a.g;
});

let prize = 1;
let nextPrize = 1;

if (arr[0].c === K) console.log(prize);
else {
  for (let i = 1; i < arr.length; i++) {
    const { g, s, b } = arr[i - 1];
    nextPrize += 1;
    if (!(arr[i].g === g && arr[i].s === s && arr[i].b === b)) {
      prize = nextPrize;
    }
    if (arr[i].c === K) {
      console.log(prize);
      break;
    }
  }
}
