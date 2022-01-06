var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split("\n");
var C = input[0].split(" ");
let n = parseInt(C[0]);
let m = parseInt(C[1]);
v = [];
let count = 0;
for (let i = 0; i < n; i++) {
    let temp = input[i + 1].split(" ");
    v[i] = [];
    for (let j = 0; j < m; j++) {
        v[i].push(parseInt(temp[j]));
        if (v[i][j] === 1) {
            count++;
        }
    }
}
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];

function bfs(sx, sy) {
    let q = [[sx, sy]];
    v[sx][sy] = 2;
    while (q.length !== 0) {
        let x = q[0][0];
        let y = q[0][1];
        q.shift();
        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (v[nx][ny] === 0) {
                    v[nx][ny] = 2;
                    q.push([nx, ny]);
                }
            }
        }
    }
}
bfs(0, 0);
let days = 0;
let cheese = 0;
while (count > 0) {
    let q = [];
    let tempArr = v.map((a) => a.slice());
    let cheeseCount = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                for (let k = 0; k < 4; k++) {
                    let nx = i + dx[k];
                    let ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if (v[nx][ny] == 2) {
                            tempArr[i][j] = 2;
                            cheeseCount++;
                            q.push([i, j]);
                            break;
                        }
                    }
                }
            }
        }
    }
    count -= cheeseCount;
    days++;
    cheese = cheeseCount;
    v = tempArr.map((a) => a.slice());
    while (q.length !== 0) {
        let sx = q[0][0];
        let sy = q[0][1];
        q.shift();
        bfs(sx, sy);
    }
}
console.log(days);
console.log(cheese);
