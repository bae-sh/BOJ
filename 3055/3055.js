let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [R, C] = input[0].split(" ").map(Number);
let sx, sy;
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];
let visited = Array.from({ length: R }, () => Array(C).fill(false));
let water = Array.from({ length: R }, () => Array(C).fill(-1));
let ans = -1;
let waterq = [];
for (let i = 0; i < R; i++) {
    for (let j = 0; j < C; j++) {
        if (input[i + 1][j] === "S") {
            sx = i;
            sy = j;
        } else if (input[i + 1][j] === "*") {
            waterq.push([i, j, 0]);
            water[i][j] = 0;
        } else if (input[i + 1][j] === "X") {
            water[i][j] = -2;
        } else if (input[i + 1][j] === "D") {
            water[i][j] = -3;
        }
    }
}

function fillWater() {
    while (waterq.length !== 0) {
        let [x, y, z] = waterq.shift();
        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
            if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (water[nx][ny] === -1) {
                    water[nx][ny] = z + 1;
                    waterq.push([nx, ny, z + 1]);
                }
            }
        }
    }
}
function bfs(x, y, depth) {
    let q = [[x, y, depth]];
    while (q.length !== 0) {
        let [x, y, z] = q.shift();
        visited[x][y] = true;
        for (let i = 0; i < 4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
            if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (!visited[nx][ny]) {
                    if (water[nx][ny] === -3) {
                        ans = z + 1;
                        return;
                    } else if (water[nx][ny] === -2) {
                        continue;
                    } else if (water[nx][ny] > z + 1 || water[nx][ny] === -1) {
                        visited[x][y] = true;
                        q.push([nx, ny, z + 1]);
                    }
                }
            }
        }
    }
}

fillWater();
bfs(sx, sy, 0);
if (ans === -1) {
    console.log("KAKTUS");
} else {
    console.log(ans);
}
