const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const str = input[1].split('');
let answer = Number.MIN_SAFE_INTEGER;
for (let i = 0; i < N; i += 2) {
  str[i] = +str[i];
}

function dfs(index, temp) {
  if (index > N - 1) {
    answer = Math.max(answer, temp);
    return;
  }
  const op = index === 0 ? '+' : str[index - 1];

  if (index + 2 < N) {
    let k = cal(str[index], str[index + 2], str[index + 1]);
    dfs(index + 4, cal(temp, k, op));
  }
  dfs(index + 2, cal(temp, str[index], op));
}

function cal(a, b, op) {
  let res = a;
  switch (op) {
    case '+':
      res += b;
      break;
    case '-':
      res -= b;
      break;
    case '*':
      res *= b;
      break;
  }
  return res;
}

dfs(0, 0);
console.log(answer);
