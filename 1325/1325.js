let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [N, M] = input[0].split(" ").map(Number);
let v = Array.from({ length: N + 1 }, () => []);
let dp = new Array(N + 1).fill(-1);
let maxValue = -1;
let ans = [];

for (let i = 1; i <= M; i++) {
    let [A, B] = input[i].split(" ").map(Number);
    if (A !== B) {
        v[B].push(A);
    }
}

function bfs(node) {
    const visited = new Array(N + 1);
    let count = 1;
    visited[node] = true;
    let q = [node];
    while (q.length) {
        let cur = q.shift();
        v[cur].map((item) => {
            if (!visited[item]) {
                q.push(item);
                visited[item] = true;
                count += 1;
            }
        });
    }
    return count;
}

for (let i = 1; i <= N; i++) {
    dp[i] = bfs(i);
    maxValue = Math.max(dp[i], maxValue);
}
for (let i = 1; i <= N; i++) {
    if (maxValue === dp[i]) {
        ans.push(i);
    }
}
console.log(ans.join(" "));
