const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input.shift();
const str = input.shift().split('');
const table = {};

for (let i = 0; i < N; i++) {
  table[String.fromCharCode(i + 65)] = +input.shift();
}

function go() {
  const st = [];
  for (let i = 0; i < str.length; i++) {
    const ch = str[i];
    if (ch === '+') {
      const a = st.pop();
      const b = st.pop();
      st.push(a + b);
    } else if (ch === '-') {
      const a = st.pop();
      const b = st.pop();
      st.push(b - a);
    } else if (ch === '*') {
      const a = st.pop();
      const b = st.pop();
      st.push(a * b);
    } else if (ch === '/') {
      const a = st.pop();
      const b = st.pop();
      st.push(b / a);
    } else {
      st.push(table[ch]);
    }
  }
  return st.pop().toFixed(2);
}

console.log(go());
