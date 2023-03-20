const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const people = input.shift().split(' ').map(Number);
people.unshift(0);
const v = [[]];
let answer = 987654321;
for (let i = 1; i <= N; i++) {
  const arr = input.shift().split(' ').map(Number);
  arr.shift();
  v.push(arr);
}

function isPossible(areaA, areaB) {
  const q = [1];
  const visited = new Array(N + 1).fill(false);

  visited[0] = true;
  visited[1] = true;
  while (q.length !== 0) {
    const index = q.shift();
    v[index].forEach(next => {
      if (!visited[next] && areaA.includes(next)) {
        visited[next] = true;
        q.push(next);
      }
    });
  }
  q.push(areaB[0]);
  visited[areaB[0]] = true;
  while (q.length !== 0) {
    const index = q.shift();
    v[index].forEach(next => {
      if (!visited[next] && areaB.includes(next)) {
        visited[next] = true;
        q.push(next);
      }
    });
  }
  if (!visited.includes(false)) {
    return true;
  }
  return false;
}
function brute({ index, areaA, areaB }) {
  if (areaA.length + areaB.length === N) {
    if (areaA.length === N || areaB.length === N) return;
    if (isPossible(areaA, areaB)) {
      let sum = 0;
      areaA.forEach(index => {
        sum += people[index];
      });
      areaB.forEach(index => {
        sum -= people[index];
      });
      answer = Math.min(answer, Math.abs(sum));
    }
  }
  if (index > N) return;

  brute({ index: index + 1, areaA: [...areaA, index], areaB: [...areaB] });
  brute({ index: index + 1, areaA: [...areaA], areaB: [...areaB, index] });
}

brute({ index: 2, areaA: [1], areaB: [] });

if (answer === 987654321) console.log(-1);
else console.log(answer);
