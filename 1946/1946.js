const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let T = +input[0];
let lineIndex = 1;
while (T--) {
  const n = +input[lineIndex++];
  const q = [];
  let answer = 0;

  for (let i = 0; i < n; i++) {
    const [x, y] = input[lineIndex++].split(' ').map(Number);
    q.push({ x, y });
  }

  q.sort((a, b) => {
    return a.x - b.x;
  });
  let maxValue = q[0].y;
  for (let i = 0; i < q.length; i++) {
    if (maxValue >= q[i].y) {
      maxValue = q[i].y;
      answer += 1;
    }
  }
  console.log(answer);
}
