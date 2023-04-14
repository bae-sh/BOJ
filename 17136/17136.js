const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const field = [];

for (let i = 0; i < 10; i++) {
  const arr = input.shift().split(' ').map(Number);
  field.push(arr);
}
