const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const K = +input[0];
const mobiusArr = new Array(1000001).fill(0);

let left = 0;
let right = 2000000000;

// arr == 1 인경우 제곱 ㄴㄴ 수의 지수합 짝
// arr == 0 인경우 제곱수
// arr == -1 인경우 제곱 ㄴㄴ 수의 지수합 홀

function mobius() {
  mobiusArr[1] = 1;
  for (let i = 1; i < 1000001; i++) {
    if (mobiusArr[i] !== 0) {
      for (let j = 2 * i; j < 1000001; j += i) {
        mobiusArr[j] -= mobiusArr[i];
      }
    }
  }
}

function notSquareCnt(num) {
  let cnt = 0;
  for (let i = 1; i * i <= num; i++) {
    cnt += mobiusArr[i] * Math.floor(num / (i * i));
  }
  return cnt;
}

mobius();

while (left + 1 < right) {
  const mid = Math.floor((left + right) / 2);
  const count = notSquareCnt(mid);

  if (count < K) {
    left = mid;
  } else {
    right = mid;
  }
}

console.log(right);
