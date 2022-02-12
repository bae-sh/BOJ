let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [N, M] = input[0].split(" ").map((e) => +e);
let ans = 0;
let friend = Array.from({ length: N }, () => Array(0));
let visit = new Array(N).fill(false);

for (let i = 1; i <= M; i++) {
    let [a, b] = input[i].split(" ").map(Number);
    friend[a].push(b);
    friend[b].push(a);
}

function dfs(depth, people) {
    if (ans === 1) {
        return;
    }
    if (depth === 4) {
        ans = 1;
        return;
    }

    friend[people].forEach((e) => {
        if (!visit[e]) {
            visit[e] = true;
            dfs(depth + 1, e);
            visit[e] = false;
        }
    });
}

for (let i = 0; i < N; i++) {
    visit[i] = true;
    dfs(0, i);
    visit[i] = false;
}

console.log(ans);
