const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const circles = new Array(5).fill([]);
let visited = new Array(5).fill(false);
const K = +input[4];
let ans = 0;

for (let i = 0; i < 4; i++) {
  circles[i + 1] = input[i].split('');
}

function move(number, way) {
  let newCircle = [...circles[number]];
  if (way === -1) {
    //반시계
    let value = newCircle.shift();
    newCircle.push(value);
    circles[number] = newCircle;
  } else {
    let value = newCircle.pop();
    newCircle.unshift(value);
    circles[number] = newCircle;
  }
}

// 2-> 오른쪽 6-> 왼쪽
function rotate(number, way) {
  const leftNumber = number - 1;
  const rightNumber = number + 1;
  visited[number] = true;
  if (leftNumber > 0 && !visited[leftNumber] && circles[leftNumber][2] !== circles[number][6]) {
    rotate(leftNumber, way * -1);
  }

  if (rightNumber < 5 && !visited[rightNumber] && circles[rightNumber][6] !== circles[number][2]) {
    rotate(rightNumber, way * -1);
  }

  move(number, way);
}

for (let i = 5; i < K + 5; i++) {
  const [number, way] = input[i].split(' ').map(Number);
  visited.fill(false);
  rotate(number, way);
}

for (let i = 1; i <= 4; i++) {
  if (circles[i][0] === '1') {
    ans += Math.pow(2, i - 1);
  }
}
console.log(ans);
