const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [A, B] = input[0].split(' ').map(Number);
const [N, M] = input[1].split(' ').map(Number);
const field = Array.from({ length: B }, () => new Array(A).fill(0));

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

const robots = [0];
let crash = false;

class Robot {
  constructor(x, y, way, number) {
    this.x = x;
    this.y = y;
    this.way = way;
    this.number = number;
  }

  move(dir) {
    if (dir === 'R') {
      this.way = (this.way + 3) % 4;
    } else if (dir === 'L') {
      this.way = (this.way + 1) % 4;
    } else if (dir === 'F') {
      const nx = this.x + dx[this.way];
      const ny = this.y + dy[this.way];
      if (0 <= nx && nx < B && 0 <= ny && ny < A) {
        if (field[nx][ny] !== 0) {
          console.log(`Robot ${this.number} crashes into robot ${field[nx][ny]}`);
          crash = true;
        } else {
          field[this.x][this.y] = 0;
          field[nx][ny] = this.number;
          this.x = nx;
          this.y = ny;
        }
      } else {
        console.log(`Robot ${this.number} crashes into the wall`);
        crash = true;
      }
    }
  }
}

for (let i = 2; i < 2 + N; i++) {
  const [y, x, way] = input[i].split(' ');
  let dir = 0;
  if (way === 'W') {
    dir = 3;
  } else if (way === 'E') {
    dir = 1;
  } else if (way === 'N') {
    dir = 2;
  }
  const robot = new Robot(Number(x - 1), Number(y - 1), Number(dir), i - 1);
  robots.push(robot);
  field[x - 1][y - 1] = i - 1;
}

function playGame() {
  for (let i = 2 + N; i < 2 + N + M; i++) {
    const [number, way, repeat] = input[i].split(' ');
    for (let j = 0; j < repeat; j++) {
      robots[Number(number)].move(way, repeat);
      if (crash) return;
    }
  }
}

playGame();

if (!crash) {
  console.log('OK');
}
