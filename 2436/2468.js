const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [a, b] = input.shift().split(' ').map(Number);
let c = b / a;

const arr = [];

let k = 2;
while (c !== 1) {
  let res = 0;
  while (c % k === 0) {
    c = c / k;
    res += 1;
  }
  if (res !== 0) arr.push(k ** res);
  k += 1;
}

let ans = [Number.MAX_SAFE_INTEGER, 0];

function cal(count, temp1, temp2) {
  if (count === arr.length) {
    if (ans[0] + ans[1] > temp1 + temp2) {
      ans = [temp1, temp2];
    }
    return;
  }
  cal(count + 1, temp1 * arr[count], temp2);
  cal(count + 1, temp1, temp2 * arr[count]);
}

cal(0, a, a);
ans.sort((a, b) => a - b);
console.log(ans[0], ans[1]);
