const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const arr = input.shift().split('');
arr.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));

function solve() {
  let st1 = [];
  let st2 = [];
  let temp = [];

  while (arr.length !== 0) {
    if (arr.length === 1) {
      const alpa = arr.shift();
      temp.push(alpa);
      break;
    }

    const a = arr.shift();
    const b = arr.shift();
    if (a === b) {
      st1.push(a);
      st2.unshift(b);
    } else {
      temp.push(a);
      arr.unshift(b);
    }
  }

  if (temp.length > 1) return "I'm Sorry Hansoo";
  return st1.join('') + temp.join('') + st2.join('');
}
console.log(solve());
