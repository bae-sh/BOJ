const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const cranes = input.shift().split(' ').map(Number);
const M = +input.shift();
const boxes = input.shift().split(' ').map(Number);

cranes.sort((a, b) => {
  return b - a;
});

boxes.sort((a, b) => {
  return b - a;
});

console.log(getTime());

function getTime() {
  if (cranes[0] < boxes[0]) return -1;

  const count = new Array(N).fill(0);

  for (let i = 0; i < M; i++) {
    let cranesIndex = 0;
    for (let j = 1; j < N; j++) {
      if (cranes[j] >= boxes[i] && count[cranesIndex] >= count[j]) {
        cranesIndex = j;
      }
    }
    count[cranesIndex] += 1;
  }

  return Math.max(...count);
}
