const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const dice = input[0].split(' ').map(Number);
const mal = new Array(4).fill(0);
const field = new Array(35).fill(0);
const turn = new Array(35).fill(0);
const score = new Array(35).fill(0);
const check = new Array(35).fill(false);

for (let i = 0; i < 30; i++) {
  field[i] = i + 1;
}
field[30] = 25;
field[31] = 32;
field[32] = 25;
field[27] = 20;
field[21] = 21;

turn[5] = 22;
turn[10] = 31;
turn[15] = 28;
turn[25] = 26;

for (let i = 0; i < 21; i++) {
  score[i] = i * 2;
}
score[22] = 13;
score[23] = 16;
score[24] = 19;
score[31] = 22;
score[32] = 24;
score[28] = 28;
score[29] = 27;
score[30] = 26;
score[25] = 25;
score[26] = 30;
score[27] = 35;

let ans = 0;
playGame(0, 0);
console.log(ans);

function playGame(cnt, sum) {
  if (cnt == 10) {
    ans = Math.max(ans, sum);
    return;
  }

  for (let i = 0; i < 4; i++) {
    const prev = mal[i];
    let now = prev;
    let move = dice[cnt];

    if (turn[now]) {
      now = turn[now];
      move -= 1;
    }
    while (move--) {
      now = field[now];
    }

    if (now != 21 && check[now]) continue;

    check[prev] = false;
    check[now] = true;
    mal[i] = now;

    playGame(cnt + 1, sum + score[now]);

    mal[i] = prev;
    check[prev] = true;
    check[now] = false;
  }
}
