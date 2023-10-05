const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let idx = 0;
const T = +input[idx++];

for (let i = 0; i < T; i++) {
  const N = +input[idx++];
  const parent = new Array(N + 1);
  const visited = new Array(N + 1).fill(false);

  for (let i = 1; i < N; i++) {
    parent[i] = i;
  }
  for (let j = 0; j < N - 1; j++) {
    const [a, b] = input[idx++].split(' ').map(Number);
    parent[b] = a;
  }
  let [a, b] = input[idx++].split(' ').map(Number);
  visited[a] = true;

  while (a !== parent[a]) {
    a = parent[a];
    visited[a] = true;
  }
  while (!visited[b]) {
    b = parent[b];
  }
  console.log(b);
}
