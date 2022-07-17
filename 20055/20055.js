const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, K] = input[0].split(' ').map(Number);
const velt = input[1].split(' ').map(Number);
let robots = [];
let stage = 0;
let count = 0;

while (count < K) {
  const lastItem = velt.pop();
  const newRobots = [];

  velt.unshift(lastItem);
  robots.forEach(index => {
    index += 1;
    if (index !== N - 1) {
      index += 1;
      if (!newRobots.includes(index) && velt[index] !== 0) {
        velt[index] -= 1;
        if (velt[index] === 0) {
          count += 1;
        }
      } else {
        index -= 1;
      }

      if (index !== N - 1) {
        newRobots.push(index);
      }
    }
  });

  if (velt[0] !== 0) {
    newRobots.push(0);
    velt[0] -= 1;
    if (velt[0] === 0) count += 1;
  }
  robots = newRobots;

  stage += 1;
}

console.log(stage);
