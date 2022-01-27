let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let line = 0;
let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];

while (true) {
    let T = 1;
    let n = +input[line++];
    let cost = [];
    let ans = [];
    if (n == 0) break;

    for (let i = 0; i < n; i++) {
        cost[i] = input[line++].split(" ").map((v) => +v);
        ans[i] = [];
        for (let j = 0; j < n; j++) {
            ans[i].push(987654321);
        }
    }
    bfs(n, cost, ans);
    console.log(`Problem ${T++}:${ans[n - 1][n - 1]}`);
}

function bfs(n, cost, ans) {
    let q = [[0, 0]];
    ans[0][0] = cost[0][0];
    while (q.length) {
        let [x, y] = q.pop();
        for (let i = 0; i < 4; i++) {
            let cur = ans[x][y];
            let nx = x + dx[i];
            let ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (ans[nx][ny] > cost[nx][ny] + cur) {
                    ans[nx][ny] = cost[nx][ny] + cur;
                    q.push([nx, ny]);
                }
            }
        }
    }
}
