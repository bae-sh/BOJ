const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();

const prime = new Array(10001).fill(true);
const primeNumbers = [];
const answer = Array.from({ length: N + 1 }, () => []);
prime[0] = false;
prime[1] = false;

for (let i = 2; i <= 100; i++) {
  if (prime[i]) {
    for (let j = i + i; j <= 10000; j += i) {
      prime[j] = false;
    }
  }
}
for (let i = 2; i < 10001; i++) {
  if (prime[i]) primeNumbers.push(i);
}
for (let i = 2; i < 10; i++) {
  if (prime[i]) answer[1].push(i);
}

for (let i = 2; i <= N; i++) {
  answer[i - 1].forEach(num => {
    for (let j = 1; j < 10; j += 2) {
      const nextNumber = Number(`${num}${j}`);
      if (checkPrime(nextNumber)) answer[i].push(nextNumber);
    }
  });
}
function checkPrime(num) {
  for (let i = 0; i < primeNumbers.length; i++) {
    const primeNum = primeNumbers[i];
    if (num <= primeNum) return true;
    if (num % primeNum === 0) return false;
  }
  return true;
}
let str = '';

answer[N].forEach(num => {
  str += `${num}\n`;
});
console.log(str);