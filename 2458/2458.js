const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input.shift().split(' ').map(Number);
const MAX_VALUE = 98654321;
const cost = Array.from({ length: N + 1 }, () => new Array(N + 1).fill(MAX_VALUE));
const answer = new Array(N + 1).fill(1);
let count = 0;

for (let i = 0; i < M; i++) {
  const [a, b] = input.shift().split(' ');
  cost[a][b] = 1;
}
for (let k = 1; k <= N; k++) {
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      if (cost[i][k] + cost[k][j] <= cost[i][j]) {
        cost[i][j] = cost[i][k] + cost[k][j];
      }
    }
  }
}
for (let i = 1; i <= N; i++) {
  for (let j = 1; j <= N; j++) {
    if (cost[i][j] !== MAX_VALUE) {
      answer[i] += 1;
      answer[j] += 1;
    }
  }
}

for (let i = 1; i <= N; i++) {
  if (answer[i] === N) count += 1;
}

console.log(count);
