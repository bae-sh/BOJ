const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const N = +input[0];
const order = new Array(9).fill(0);
const check = new Array(9).fill(false);

let ans = 0;

makeOrder(0);

function makeOrder(index) {
  if (index === 9) {
    playGame();
    return;
  }
  if (index === 3) index += 1;
  for (let i = 1; i < 9; i++) {
    if (!check[i]) {
      order[index] = i;
      check[i] = true;
      makeOrder(index + 1);
      check[i] = false;
      order[index] = 0;
    }
  }
}

function playGame() {
  let score = 0;
  let count = 0;

  for (let i = 1; i <= N; i++) {
    const arr = input[i].split(' ').map(Number);
    let player = new Array(3).fill(0);
    let outPlayer = 0;
    while (outPlayer < 3) {
      const index = order[count % 9];
      const hitScore = arr[index];
      if (hitScore === 0) {
        outPlayer += 1;
      } else if (hitScore === 1) {
        if (player[2] === 1) score += 1;
        player[2] = player[1];
        player[1] = player[0];
        player[0] = 1;
      } else if (hitScore == 2) {
        for (let i = 0; i < 2; i++) {
          if (player[2 - i] === 1) score += 1;
        }
        player = [0, 1, player[0]];
      } else if (hitScore === 3) {
        for (let i = 0; i < 3; i++) {
          if (player[i] === 1) score += 1;
        }
        player = [0, 0, 1];
      } else {
        score += 1;
        for (let i = 0; i < 3; i++) {
          if (player[i] === 1) score += 1;
          player[i] = 0;
        }
      }
      count += 1;
    }
  }
  ans = Math.max(ans, score);
}

console.log(ans);
