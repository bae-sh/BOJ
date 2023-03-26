const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const arr = [];

for (let i = 0; i < N; i++) {
  const data = input.shift().split(' ');
  arr.push({ name: data[0], day: Number(data[1]), month: Number(data[2]), year: Number(data[3]) });
}

arr.sort((a, b) => {
  if (a.year === b.year) {
    if (a.month === b.month) {
      return a.day - b.day;
    }
    return a.month - b.month;
  }
  return a.year - b.year;
});

console.log(arr[N - 1].name);
console.log(arr[0].name);
