const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let index = 0;
const T = +input[index++];
let answer = '';
const binarySearch = (list, target, left, right) => {
  let mid = 0;

  while (left <= right) {
    mid = Math.floor((left + right) / 2);

    if (list[mid] === target) {
      return mid;
    }
    if (list[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
};
for (let i = 0; i < T; i++) {
  const N = +input[index++];
  const arr = input[index++].split(' ').map(Number);
  arr.sort((a, b) => a - b);
  const M = +input[index++];
  const query = input[index++].split(' ').map(Number);
  query.forEach(num => {
    answer += binarySearch(arr, num, 0, N - 1) !== -1 ? '1\n' : '0\n';
  });
}

console.log(answer);
