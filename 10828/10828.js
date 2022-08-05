const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const st = new Array(N).fill(0);
let index = -1;
let ans = '';
for (let i = 0; i < N; i++) {
  const [str, num] = input[i + 1].split(' ');

  switch (str) {
    case 'push':
      index += 1;
      st[index] = Number(num);
      break;
    case 'pop':
      if (index >= 0) {
        ans += st[index] + '\n';
        index -= 1;
      } else {
        ans += '-1\n';
      }
      break;
    case 'size':
      ans += index + 1 + '\n';
      break;
    case 'empty':
      if (index >= 0) {
        ans += '0\n';
      } else {
        ans += '1\n';
      }
      break;
    case 'top':
      if (index >= 0) {
        ans += st[index] + '\n';
      } else {
        ans += '-1\n';
      }
  }
}
console.log(ans);
