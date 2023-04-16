const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const P = +input[0];

for (let i = 0; i < P; i++) {
  const [number, ...arr] = input[i + 1].split(' ').map(Number);
  let curArr = [];
  let answer = 0;
  for (let i = 0; i < 20; i++) {
    let isMoved = false;
    const student = arr[i];
    for (let j = 0; j < i; j++) {
      if (curArr[j] > student) {
        if (j === 0) {
          answer += curArr.length;
          curArr.unshift(student);
          isMoved = true;
          break;
        }

        curArr = [...curArr.slice(0, j), student, ...curArr.slice(j)];
        answer += curArr.length - j - 1;
        isMoved = true;
        break;
      }
    }
    if (!isMoved) curArr.push(student);
  }
  console.log(number, answer);
}
