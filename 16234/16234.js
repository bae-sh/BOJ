var fs = require("fs");
var input = fs.readFileSync("input.txt").toString().split("\n");
var C = input[0].split(" ");
let N = parseInt(C[0]);
let L = parseInt(C[1]);
let R = parseInt(C[2]);
let v = [];
for (let i = 1; i <= N; i++) {
    v.push(input[i].split(" "));
}
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];
function bfs(sx, sy, check) {
    let q = [[sx, sy]];
    let q2 = [[sx, sy]];
    check[sx][sy] = true;
    let sum = 0;
    let count = 0;
    while (q.length != 0) {
        let x = q[0][0];
        let y = q[0][1];
        q.shift();
        sum += parseInt(v[x][y]);
        count += 1;

        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
            if (
                0 <= nx &&
                nx < N &&
                0 <= ny &&
                ny < N &&
                check[nx][ny] === false
            ) {
                let gap = Math.abs(v[x][y] - v[nx][ny]);
                if (L <= gap && gap <= R) {
                    check[nx][ny] = true;
                    q.push([nx, ny]);
                    q2.push([nx, ny]);
                }
            }
        }
    }
    sum = Math.floor(sum / count);

    while (q2.length != 0) {
        let x = q2[0][0];
        let y = q2[0][1];
        q2.shift();
        v[x][y] = sum;
    }
    if (count == 1) {
        return 0;
    }
    return count;
}
function go() {
    let count = 0;
    let days = 0;

    while (true) {
        let check = [];
        for (let i = 0; i < N; i++) {
            check[i] = [];
            for (let j = 0; j < N; j++) {
                check[i][j] = false;
            }
        }
        for (let i = 0; i < N; i++) {
            for (let j = 0; j < N; j++) {
                if (check[i][j] === false) {
                    count += bfs(i, j, check);
                }
            }
        }
        console.log(v);
        if (count == 0) {
            console.log(days);
            return;
        }
        count = 0;
        days++;
    }
}
go();
