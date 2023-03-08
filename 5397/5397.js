const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let T = +input[0];
let lineIndex = 1;
while (T-- > 0) {
  const arr = input[lineIndex++].split('');
  const st1 = [];
  const st2 = [];
  arr.forEach(char => {
    if (char === '<') {
      if (st1.length !== 0) {
        const value = st1.pop();
        st2.push(value);
      }
    } else if (char === '>') {
      if (st2.length !== 0) {
        const value = st2.pop();
        st1.push(value);
      }
    } else if (char === '-') {
      st1.pop();
    } else {
      st1.push(char);
    }
  });
  const pw = st1.join('') + st2.reverse().join('');

  console.log(pw);
}
