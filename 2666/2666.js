const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const door = input.shift().split(' ').map(Number);
door.sort((a, b) => a - b);
const M = +input.shift();
const arr = [];
let answer = Number.MAX_SAFE_INTEGER;

for (let i = 0; i < M; i++) {
  arr.push(+input.shift());
}

moveDoor(door[0], door[1], 0, 0);
function moveDoor(left, right, index, ans) {
  if (index === M) {
    answer = Math.min(answer, ans);
    return;
  }
  const curIndex = arr[index];
  if (curIndex <= left) {
    moveDoor(curIndex, right, index + 1, ans + left - curIndex);
  } else if (curIndex >= right) {
    moveDoor(left, curIndex, index + 1, ans + curIndex - right);
  } else {
    moveDoor(curIndex, right, index + 1, ans + curIndex - left);
    moveDoor(left, curIndex, index + 1, ans + right - curIndex);
  }
}

console.log(answer);
