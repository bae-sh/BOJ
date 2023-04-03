const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
let answer = 0;

const st = [{ height: +input[N - 1], count: 0 }];

for (let i = N - 2; i >= 0; i--) {
  const curHeight = +input[i];
  let curCount = 0;
  while (st.length !== 0) {
    const { height, count } = st[0];
    if (curHeight > height) {
      curCount += count + 1;
      st.shift();
      answer += count;
    } else {
      break;
    }
  }
  st.unshift({ height: curHeight, count: curCount });
}
while (st.length !== 0) {
  const { count } = st.shift();
  answer += count;
}
console.log(answer);
