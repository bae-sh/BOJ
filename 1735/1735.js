const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [a, b] = input[0].split(' ').map(Number);
const [c, d] = input[1].split(' ').map(Number);

let [e, f] = [a * d + c * b, b * d];
const mod = gcd(f, e);
console.log(parseInt(e / mod), parseInt(f / mod));

function gcd(num1, num2) {
  if (num1 % num2 === 0) return num2;
  return gcd(num2, num1 % num2);
}
