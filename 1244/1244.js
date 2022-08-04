const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const switches = input[1].split(' ').map(Number);
const query = +input[2];

switches.unshift(-1);
for (let i = 0; i < query; i++) {
  const [student, num] = input[i + 3].split(' ').map(Number);
  if (student === 1) {
    for (let j = num; j <= N; j += num) {
      switches[j] ^= 1;
    }
  } else {
    switches[num] ^= 1;
    for (let j = 0; j < N; j++) {
      const left = num - j;
      const right = num + j;
      if (0 < left && right <= N) {
        if (switches[left] === switches[right]) {
          switches[left] ^= 1;
          switches[right] ^= 1;
        } else {
          break;
        }
      }
    }
  }
}

for (let i = 1; i <= N; i++) {
  process.stdout.write(switches[i] + ' ');
  if (i % 20 === 0) {
    console.log();
  }
}
