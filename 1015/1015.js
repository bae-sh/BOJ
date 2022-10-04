const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input[0];
const arr = input[1].split(' ').map(Number);

const newArr = [];
const ans = new Array(N).fill(0);

arr.forEach((value, idx) => {
  newArr.push({ value, idx });
});

newArr.sort((a, b) => {
  if (a.value === b.value) return a.idx - b.idx;
  return a.value - b.value;
});

newArr.forEach(({ idx }, index) => {
  ans[idx] = index;
});

console.log(ans.join(' '));
