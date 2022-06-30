const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [str1, str2] = input[0].split(' ');
let ans = 987654321;
for (let i = 0; i <= str2.length - str1.length; i++) {
  let count = 0;
  for (let j = 0; j < str1.length; j++) {
    if (str1[j] !== str2[i + j]) count++;
  }
  ans = Math.min(ans, count);
}
console.log(ans);
