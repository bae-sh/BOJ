const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, Q] = input[0].split(' ').map(Number);
let arr = input[1].split(' ').map(Number);
let tree = new Array(arr.length + 1);

function setTree(start, end, index) {
  const mid = Math.floor((start + end) / 2);

  if (start === end) {
    tree[index] = arr[start - 1];
    return tree[index];
  }
  tree[index] = setTree(start, mid, index * 2) + setTree(mid + 1, end, index * 2 + 1);
  return tree[index];
}

function sum(start, end, left, right, index) {
  const mid = Math.floor((start + end) / 2);

  if (right < start || end < left) {
    return 0;
  }
  if (left <= start && end <= right) {
    return tree[index];
  }

  return sum(start, mid, left, right, index * 2) + sum(mid + 1, end, left, right, index * 2 + 1);
}

function update(start, end, target, diff, index) {
  const mid = Math.floor((start + end) / 2);

  if (target < start || end < target) return;
  if (start <= target && target <= end) tree[index] += diff;
  if (start === end) {
    arr[start - 1] += diff;
    return;
  }

  update(start, mid, target, diff, index * 2);
  update(mid + 1, end, target, diff, index * 2 + 1);
}

setTree(1, N, 1);

for (let i = 2; i < Q + 2; i++) {
  let [x, y, a, b] = input[i].split(' ').map(Number);
  const diff = b - arr[a - 1];

  if (x > y) [x, y] = [y, x];
  console.log(sum(1, N, x, y, 1));
  update(1, N, a, diff, 1);
}
