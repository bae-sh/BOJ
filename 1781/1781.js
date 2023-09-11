//1. 한문제 해결하는데 1 비용 소모
//2. 최고로 많이 받을 수 있는 라면수
//3. 정렬? -> N 20만
//4. dp로 날짜당 수? 20만
//5. 날짜별로 1씩 증가해서 찾아보자

const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
let index = 0;
const N = +input[index++];
const problems = [];

for (let i = index; i <= N; i++) {
  const [a, b] = input[i].split(' ').map(Number);
  problems.push({ deadLine: a, ramen: b });
}

problems.sort((a, b) => {
  if (a.deadLine !== b.deadLine) return a.deadLine - b.deadLine;
  return b.ramen - a.ramen;
});

let day = 1;
let ans = 0;
let idx = 0;
while (problems.length > idx) {
  if (problems[idx].deadLine < day) {
    idx += 1;
    continue;
  }

  ans += problems[idx].ramen;
  idx += 1;
  day += 1;
}

console.log(ans);
