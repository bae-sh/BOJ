let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let line = 0;
let T = +input[line++];
let ans;
while (T--) {
    let [N, M] = input[line++].split(" ").map((v) => +v);
    let country = [];
    let visit = [];
    ans = 0;
    for (let i = 0; i <= N; i++) {
        country[i] = [];
        visit[i] = false;
    }
    for (let i = 0; i < M; i++) {
        let [a, b] = input[line++].split(" ").map((v) => +v);
        country[a].push(b);
        country[b].push(a);
    }
    go(1, visit, country);
    console.log(ans);
}
function go(x, visit, country) {
    visit[x] = true;
    country[x].forEach((e) => {
        if (!visit[e]) {
            ans++;
            go(e, visit, country);
        }
    });
}
