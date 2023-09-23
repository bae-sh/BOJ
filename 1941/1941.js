//이다솜파 최소 4명 (7명중)
// 브르트포스 중복을 제거
// 숫자로 표현 후 정렬 한다음 방문 여부 확인

const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const field = [];
for (let i = 0; i < 5; i++) {
  const arr = input.shift().split('');
  field.push(arr);
}

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
let ans = 0;

for (let i = 0; i < 25; i++) {
  go(i, [i]);
}
function go(x, arr) {
  if (arr.length === 7) {
    if (isJoin(arr)) {
      ans += 1;
    }
    return;
  }

  for (let i = x + 1; i < 25; i++) {
    go(i, [...arr, i]);
  }
}

function isJoin(arr) {
  const queue = [arr[0]];
  const v = [arr[0]];
  let sCount = 0;
  while (queue.length > 0) {
    const n = queue.shift();
    const [x, y] = [Math.floor(n / 5), n % 5];
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (!(0 <= nx && nx < 5 && 0 <= ny && ny < 5)) continue;
      const num = nx * 5 + ny;
      if (v.includes(num)) continue;
      if (!arr.includes(num)) continue;

      queue.push(num);
      v.push(num);
    }
  }

  v.forEach(item => {
    if (field[Math.floor(item / 5)][item % 5] === 'S') sCount += 1;
  });

  if (sCount >= 4 && v.length === 7) {
    return true;
  }
  return false;
}
console.log(ans);
