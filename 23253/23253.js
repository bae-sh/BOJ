const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M] = input[0].split(' ').map(Number);
const st = [];
for (let i = 1; i <= M; i++) {
  const arr = input[2 * i].split(' ').map(Number);
  st.push(arr);
}
let answer = 'Yes';
st.forEach(arr => {
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      answer = 'No';
      break;
    }
  }
});
console.log(answer);
