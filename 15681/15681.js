let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [N, R, Q] = input[0].split(" ").map(Number);
let nodes = Array.from({ length: N + 1 }, () => []);
let count = new Array(N + 1).fill(1);
let visit = new Array(N + 1).fill(false);
for (let i = 1; i <= N - 1; i++) {
    let [x, y] = input[i].split(" ").map(Number);
    nodes[x].push(y);
    nodes[y].push(x);
}

function dfs(x) {
    if (visit[x]) return count[x];

    visit[x] = true;
    nodes[x].map((node) => {
        if (!visit[node]) {
            count[x] += dfs(node);
        }
    });
    return count[x];
}

dfs(R);

let ans = [];
for (let i = N; i < N + Q; i++) {
    let x = +input[i];
    ans.push(x);
}
console.log(ans.join("\n"));
