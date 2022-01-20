var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split("\n");
const N = Number(input[0]);
let len = Number(input[1]);
let vec = [];
let ans = [1];
for (let i = 0; i <= N; i++) {
    vec[i] = [];
}
for (let i = 0; i < len; i++) {
    let li = input[i + 2].split(" ");
    let a = Number(li[0]);
    let b = Number(li[1]);
    vec[a].push(b);
    vec[b].push(a);
}
function dfs(num, depth) {
    if (depth > 1) {
        return;
    }
    for (let i = 0; i < vec[num].length; i++) {
        let cur = vec[num][i];
        ans.push(cur);
        dfs(cur, depth + 1);
    }
}
dfs(1, 0);
ans = new Set(ans);
console.log(ans.size - 1);
