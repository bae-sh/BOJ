const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dx = [1, -1, 0, 0, 1, -1, 1, -1];
const dy = [0, 0, -1, 1, 1, 1, -1, -1];

let [king, rock, N] = input[0].split(' ');
let kingPos = { x: king[0].charCodeAt() - 65, y: king[1].charCodeAt() - 49 };
let rockPos = { x: rock[0].charCodeAt() - 65, y: rock[1].charCodeAt() - 49 };

for (let i = 0; i < N; i++) {
  const idx = move(input[i + 1]);
  const knx = kingPos.x + dx[idx];
  const kny = kingPos.y + dy[idx];

  if (0 <= knx && knx < 8 && 0 <= kny && kny < 8) {
    if (knx === rockPos.x && kny === rockPos.y) {
      const rnx = rockPos.x + dx[idx];
      const rny = rockPos.y + dy[idx];

      if (0 <= rnx && rnx < 8 && 0 <= rny && rny < 8) {
        kingPos = { x: knx, y: kny };
        rockPos = { x: rnx, y: rny };
      }
    } else {
      kingPos = { x: knx, y: kny };
    }
  }
}
console.log(String.fromCharCode(kingPos.x + 65) + String.fromCharCode(kingPos.y + 49));
console.log(String.fromCharCode(rockPos.x + 65) + String.fromCharCode(rockPos.y + 49));
function move(str) {
  switch (str) {
    case 'R':
      return 0;
    case 'L':
      return 1;
    case 'B':
      return 2;
    case 'T':
      return 3;
    case 'RT':
      return 4;
    case 'LT':
      return 5;
    case 'RB':
      return 6;
    case 'LB':
      return 7;
  }
}
