const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();

const dices = [];
const revIndex = [5, 3, 4, 1, 2, 0];
let ans = 0;

for (let i = 0; i < N; i++) {
  const arr = input.shift().split(' ').map(Number);
  dices.push(arr);
}
for (let i = 0; i < 6; i++) {
  check(dices[0][i], 0, 0);
}
function check(num, count, sum) {
  if (count >= N) {
    ans = Math.max(ans, sum);
    return;
  }
  const curIndex = dices[count].indexOf(num);
  const maxNum = Math.max(
    ...dices[count].filter((_, index) => index !== curIndex && index !== revIndex[curIndex]),
  );
  check(dices[count][revIndex[curIndex]], count + 1, sum + maxNum);
}

console.log(ans);
