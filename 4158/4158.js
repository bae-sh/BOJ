const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const binarySearch = (target, data) => {
  let low = 0;
  let high = data.length - 1;

  while (low <= high) {
    let mid = Math.floor((low + high) / 2);

    if (target === data[mid]) {
      return mid;
    } else if (target > data[mid]) {
      low = mid + 1;
    } else if (target < data[mid]) {
      high = mid - 1;
    }
  }
  return -1;
};

while (true) {
  const [N, M] = input.shift().split(' ').map(Number);
  if (N === 0 && M === 0) break;
  let answer = 0;
  const arr = [];
  let index = 0;
  for (let i = 0; i < N; i++) {
    const num = +input.shift();
    arr.push(num);
  }
  for (let i = 0; i < M; i++) {
    const num = +input.shift();
    while (true) {
      if (index >= arr.length) break;
      if (arr[index] === num) {
        answer += 1;
        break;
      } else if (arr[index] > num) {
        break;
      } else {
        index += 1;
      }
    }
  }
  console.log(answer);
}
