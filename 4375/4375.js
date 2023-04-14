const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

for (let i = 0; ; i++) {
  const num = +input[i];
  if (!isNaN(num)) {
    let a = 1;
    while (true) {
      console.log(a);
      if (a % num === 0) {
        console.log(`${a}`.length);
        break;
      }
      a = a * 10 + 1;
    }
  }
}
