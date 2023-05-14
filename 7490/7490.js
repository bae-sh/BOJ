const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let ans = [];
const T = +input.shift();

function calculate(a, b, op) {
  if (op === '+') return a + b;
  else if (op === '-') return a - b;
}
function bruteForce(n, stack) {
  if (stack.length === n - 1) {
    let string = '';
    let newString = '';
    for (let i = 1; i < n; i++) {
      string += i + stack.shift();
    }
    string += n;

    newString = string.replaceAll(' ', '').split('');
    let answer = 0;
    let temp = 0;
    let op = '+';
    for (let i = 0; i < newString.length; i++) {
      if (newString[i] === '+' || newString[i] === '-') {
        answer = calculate(answer, temp, op);
        op = newString[i];
        temp = 0;
      } else {
        temp = temp * 10 + Number(newString[i]);
      }
    }
    answer = calculate(answer, temp, op);
    if (answer === 0) {
      ans.push(string);
    }
    return;
  }
  bruteForce(n, [...stack, '+']);
  bruteForce(n, [...stack, '-']);
  bruteForce(n, [...stack, ' ']);
}
for (let i = 0; i < T; i++) {
  const N = +input.shift();
  ans = [];
  bruteForce(N, []);
  ans.sort((a, b) => {
    for (let i = 1; i < N * 2; i += 2) {
      if (a[i].charCodeAt(0) - b[i].charCodeAt(0) !== 0)
        return a[i].charCodeAt(0) - b[i].charCodeAt(0);
    }
  });
  ans.forEach(s => console.log(s));

  console.log();
}
