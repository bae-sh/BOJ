const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const N = +input.shift();
const arr = input.shift().split(' ').map(Number).reverse();
const ans = [];
const st = [];

const counts = new Array(1_000_001).fill(0);

arr.forEach(item => {
  counts[item] += 1;
});

for (const item of arr) {
  while (st.length !== 0) {
    const topItem = st[st.length - 1];
    if (counts[item] < counts[topItem]) {
      st.push(item);
      ans.push(topItem);
      break;
    } else {
      st.pop();
    }
  }

  if (st.length === 0) {
    st.push(item);
    ans.push(-1);
  }
}

console.log(ans.reverse().join(' '));
