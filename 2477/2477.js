const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const arr = [];
let area = 0;
const k = +input.shift();

for (let i = 0; i < 6; i++) {
  const [a, b] = input.shift().split(' ').map(Number);
  arr.push({ a, b });
}

arr.push(...arr);

for (let i = 0; i < 6; i++) {
  if (arr[i].a === arr[i + 2].a && arr[i + 1].a === arr[i + 3].a) {
    area = (arr[i].b + arr[i + 2].b) * (arr[i + 1].b + arr[i + 3].b) - arr[i + 1].b * arr[i + 2].b;
    break;
  }
}

console.log(area * k);
