const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let str = input.shift();
const pat = input.shift();
let answer = 0;

while (true) {
  const index = str.indexOf(pat);
  if (index === -1) {
    console.log(answer);
    break;
  }
  answer += 1;
  str = str.substring(index + pat.length);
}
