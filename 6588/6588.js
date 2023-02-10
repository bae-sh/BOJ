const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().trim().split('\n').map(Number);
const MAX = 1000001;
const isPrime = new Array(MAX).fill(true);
const primes = [];
let answer = '';
isPrime[0] = false;
isPrime[1] = false;

function setPrime() {
  for (let i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (let j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for (let i = 2; i < MAX; i++) {
    if (isPrime[i]) {
      primes.push(i);
    }
  }
}
setPrime();

function printGoldbach(num) {
  for (let i = 0; i < primes.length; i++) {
    if (isPrime[num - primes[i]]) {
      answer += `${num} = ${primes[i]} + ${num - primes[i]}\n`;
      return true;
    }
  }
  return false;
}

input.forEach(num => {
  if (num === 0) return;
  if (!printGoldbach(num)) {
    answer += "Goldbach's conjecture is wrong.\n";
  }
});

console.log(answer);
