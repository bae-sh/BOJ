const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const arr = input.shift().split(' ').map(Number);

let ans = Number.MAX_SAFE_INTEGER;
let [l, r] = [0, 1_000_000_000];

while (l < r) {
  const mid = Math.floor((l + r) / 2);
  const isPossible = playGame(mid);
  if (isPossible) {
    r = mid;
  } else {
    l = mid + 1;
  }
}

function playGame(num) {
  let count = 0;
  let maxSum = 0;
  let sum = 0;

  for (let i = 0; i < arr.length; i++) {
    if (sum + arr[i] <= num) {
      sum += arr[i];
    } else {
      maxSum = Math.max(maxSum, sum);
      count += 1;
      sum = arr[i];
    }
  }
  maxSum = Math.max(maxSum, sum);
  count += 1;

  if (count <= M) {
    ans = Math.min(ans, maxSum);
    return true;
  } else if (count > M) {
    return false;
  }
}

console.log(ans);
