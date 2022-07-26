const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('');

let str = '';
let rev = true;
let buffer = [];

input.forEach(c => {
  if (rev) {
    if (c === ' ') {
      str += buffer.join('') + c;
      buffer = [];
    } else if (c === '<') {
      str += buffer.join('') + c;
      rev = false;
      buffer = [];
    } else {
      buffer.unshift(c);
    }
  } else {
    str += c;

    if (c === '>') {
      rev = true;
    }
  }
});
str += buffer.join('');

console.log(str.replace(/\n/g, ''));
