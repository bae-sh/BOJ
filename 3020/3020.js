const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, H] = input[0].split(' ').map(Number);
const obstacle1 = [];
const obstacle2 = [];
const answer = new Array(H).fill(0);
const answer1 = new Array(H).fill(0);
const answer2 = new Array(H).fill(0);

for (let i = 1; i <= N; i += 2) {
  const height = +input[i];
  obstacle1.push(height);
}
for (let i = 2; i <= N; i += 2) {
  const height = +input[i];
  obstacle2.push(height);
}

obstacle1.forEach(height => {
  answer1[height - 1] += 1;
});
for (let i = H - 1; i > 0; i--) {
  answer1[i - 1] += answer1[i];
}
obstacle2.forEach(height => {
  answer2[H - height] += 1;
});
for (let i = 1; i < H; i++) {
  answer2[i] += answer2[i - 1];
}
for (let i = 0; i < H; i++) {
  answer[i] = answer1[i] + answer2[i];
}
const minValue = Math.min(...answer);
let count = 0;

answer.forEach(value => {
  if (minValue === value) count++;
});
console.log(minValue + ' ' + count);
