const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
let answer = 0;

for (let i = 0; i < N; i++) {
  const str = input.shift().split('');
  const st = [];
  str.forEach(item => {
    if (st.length === 0 || st[st.length - 1] !== item) st.push(item);
    else st.pop();
  });
  if (st.length === 0) answer += 1;
}

console.log(answer);
