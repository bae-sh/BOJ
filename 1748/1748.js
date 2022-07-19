const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let number = +input[0];
let ans = 0;
let digit = 0;
while (number > 0) {
  const count = 9 * Math.pow(10, digit);
  if (number > count) {
    ans += count * (digit + 1);
    number -= count;
    digit += 1;
  } else {
    ans += number * (digit + 1);
    break;
  }
}

console.log(ans);
