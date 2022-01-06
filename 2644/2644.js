var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split("\n");
let C = parseInt(input[0]);
let start = parseInt(input[1].split(" ")[0]);
let end = parseInt(input[1].split(" ")[1]);
let m = parseInt(input[2]);
let list = [];
for (let i = 0; i <= C; i++) {
    list[i] = [];
}
for (let i = 0; i < m; i++) {
    let x = parseInt(input[3 + i].split(" ")[0]);
    let y = parseInt(input[3 + i].split(" ")[1]);
    list[x].push(y);
    list[y].push(x);
}

function dfs(start, end, list) {
    let st = [start];
    let ans = [];
    for (let i = 1; i <= C; i++) {
        ans[i] = -1;
    }
    ans[start] = 0;
    while (st.length != 0) {
        let cur = st.pop();
        for (let i = 0; i < list[cur].length; i++) {
            let next = list[cur][i];
            if (ans[next] === -1) {
                ans[next] = ans[cur] + 1;
                st.push(next);
            }
        }
    }
    return ans[end];
}
console.log(dfs(start, end, list));
