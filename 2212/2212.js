const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const K = +input[1];
const sensors = input[2].split(' ').map(Number);
const gaps = [];
let answer = 0;

sensors.sort((a, b) => {
  return a - b;
});

for (let i = 0; i < sensors.length - 1; i++) {
  gaps.push(sensors[i + 1] - sensors[i]);
}

gaps.sort((a, b) => {
  return a - b;
});

for (let i = 0; i < N - K; i++) {
  answer += gaps[i];
}

console.log(answer);
