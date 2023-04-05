const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const arr = input.shift().split(' ').map(Number);

const minusArr = [];
const plusArr = [];
arr.forEach(num => (num > 0 ? plusArr.push(num) : minusArr.push(num)));
minusArr.sort((a, b) => a - b);
plusArr.sort((a, b) => b - a);

let minusAns = -minusArr[0] || 0;
for (let i = M; i < minusArr.length; i += M) {
  minusAns -= minusArr[i] * 2;
}
for (let i = 0; i < plusArr.length; i += M) {
  minusAns += plusArr[i] * 2;
}

let plusAns = plusArr[0] || 0;
for (let i = 0; i < minusArr.length; i += M) {
  plusAns -= minusArr[i] * 2;
}
for (let i = M; i < plusArr.length; i += M) {
  plusAns += plusArr[i] * 2;
}
console.log(Math.min(minusAns, plusAns));
