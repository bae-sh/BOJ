var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split("\n");
let N = parseInt(input[0]);
let list = input[1].split(" ");
let deleteNode = parseInt(input[2]);
let child = [];
let root = -1;
for (let i = 0; i < N; i++) {
    child[i] = [];
}
for (let i = 0; i < N; i++) {
    let node = parseInt(list[i]);
    if (node === -1) {
        root = i;
        continue;
    }
    if (i !== deleteNode) {
        child[node].push(i);
    }
}
function dfs(node, child) {
    if (child[node].length === 0) {
        return 1;
    }

    let ans = 0;
    for (let i = 0; i < child[node].length; i++) {
        ans += dfs(child[node][i], child);
    }
    return ans;
}
if (deleteNode === root) {
    console.log(0);
} else {
    console.log(dfs(root, child));
}
