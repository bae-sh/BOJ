const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const n = +input[0];
const regex = /^(100+1+|01)+$/;
for (let i = 1; i <= n; i++) {
  const str = input[i];
  if (regex.test(str)) console.log('YES');
  else console.log('NO');
}
