const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
const [N, M, K] = input[0].split(' ').map(Number);

const dx = [-1, -1, 0, 1, 1, 1, 0, -1];
const dy = [0, 1, 1, 1, 0, -1, -1, -1];

const q = [];

for (let i = 1; i <= M; i++) {
  let [r, c, weight, speed, way] = input[i].split(' ').map(Number);
  r -= 1;
  c -= 1;
  q.push({ r, c, weight, speed, way });
}

play();

function play() {
  for (let i = 0; i < K; i++) {
    const newQ = [];
    let temp = [];
    while (q.length !== 0) {
      const { r, c, weight, speed, way } = q.pop();

      let nx = r + ((dx[way] * speed) % N);
      let ny = c + ((dy[way] * speed) % N);
      nx = nx >= N ? nx - N : nx < 0 ? nx + N : nx;
      ny = ny >= N ? ny - N : ny < 0 ? ny + N : ny;
      newQ.push({ r: nx, c: ny, weight, speed, way });
    }
    newQ.sort((a, b) => {
      if (a.r !== b.r) return a.r - b.r;
      return a.c - b.c;
    });
    while (newQ.length !== 0) {
      const cur = newQ.shift();

      if (temp.length === 0) temp.push(cur);
      else {
        const prev = temp[temp.length - 1];
        if (prev.r === cur.r && prev.c === cur.c) {
          temp.push(cur);
        } else {
          sumFireball(temp);
          temp = [cur];
        }
      }
    }

    if (temp.length !== 0) {
      sumFireball(temp);
    }
  }
  let ans = 0;
  q.forEach(({ weight }) => {
    ans += weight;
  });
  console.log(ans);
}

function sumFireball(arr) {
  if (arr.length === 1) {
    const fireball = arr.pop();
    q.push(fireball);
  } else {
    const { r, c } = arr[0];
    let sumWeight = 0;
    let allEven = true;
    let sumSpeed = 0;
    let count = arr.length;

    arr.forEach(fireball => {
      sumWeight += fireball.weight;
      sumSpeed += fireball.speed;
      if (arr[0].way % 2 !== fireball.way % 2) {
        allEven = false;
      }
    });
    sumWeight = Math.floor(sumWeight / 5);
    sumSpeed = Math.floor(sumSpeed / count);

    if (sumWeight === 0) return;

    allEven = allEven ? [0, 2, 4, 6] : [1, 3, 5, 7];

    for (let i = 0; i < 4; i++) {
      const fireball = { r, c, weight: sumWeight, speed: sumSpeed, way: allEven[i] };
      q.push(fireball);
    }
  }
}
