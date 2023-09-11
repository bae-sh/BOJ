const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let index = 0;
const [V, E] = input[index++].split(' ').map(Number);
const arr = Array.from({ length: V + 1 }, () => new Array(V + 1).fill(Number.MAX_VALUE));

for (let i = 0; i < E; i++) {
  const [a, b, c] = input[index++].split(' ').map(Number);
  arr[a][b] = c;
}

for (let k = 1; k <= V; k++) {
  for (let i = 1; i <= V; i++) {
    for (let j = 1; j <= V; j++) {
      const cost = arr[i][k] + arr[k][j];

      if (arr[i][j] > cost) arr[i][j] = cost;
    }
  }
}

let ans = Number.MAX_SAFE_INTEGER;

for (let i = 1; i <= V; i++) {
  ans = Math.min(ans, arr[i][i]);
}

ans === Number.MAX_SAFE_INTEGER ? console.log(-1) : console.log(ans);
