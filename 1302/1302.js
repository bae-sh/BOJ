const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const books = {};
const arr = [];
for (let i = 1; i <= N; i++) {
  const book = input[i];
  if (Object.keys(books).includes(book)) {
    books[book] += 1;
  } else {
    books[book] = 1;
  }
}
for (let name in books) {
  arr.push([name, books[name]]);
}

arr.sort((a, b) => {
  if (a[1] === b[1]) return a[0] < b[0] ? -1 : 0;
  return b[1] - a[1];
});

console.log(arr[0][0]);
