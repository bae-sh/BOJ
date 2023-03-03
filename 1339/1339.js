const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const table = new Array(26).fill(0);
let [ans, count] = [0, 9];

for (let i = 1; i <= N; i++) {
  const str = input[i].split('');
  str.forEach((char, index) => {
    const value = Math.pow(10, str.length - 1 - index);
    const indexCode = char.charCodeAt(0) - 65;

    table[indexCode] += value;
  });
}
table.sort((a, b) => {
  return b - a;
});

for (let i = 0; i < 26; i++) {
  if (table[i] !== 0) {
    ans += table[i] * count;
    count--;
  }
}
console.log(ans);
