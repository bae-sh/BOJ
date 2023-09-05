const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

let index = 0;
while (true) {
  const [m, n] = input[index++].split(' ').map(Number);
  if (m === 0 && n === 0) break;

  const arr = [];
  const parent = new Array(m);

  for (let i = 0; i < m; i++) {
    parent[i] = i;
  }

  for (let i = 0; i < n; i++) {
    const [x, y, z] = input[index++].split(' ').map(Number);
    arr.push({ x, y, z });
  }

  let ans = 0;
  let total = 0;
  arr.sort((a, b) => a.z - b.z);

  arr.forEach(({ x, y, z }) => {
    total += z;
    const xParent = findParent(x);
    const yParent = findParent(y);
    if (xParent !== yParent) {
      parent[xParent] = yParent;
      ans += z;
    }
  });

  console.log(total - ans);
  function findParent(x) {
    if (x === parent[x]) return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
  }
}
