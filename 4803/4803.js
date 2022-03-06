let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");

let count = 1;
let idx = 0;
let parent = new Array(501);
let cycles = [];

function findParent(x) {
    if (x === parent[x]) {
        return x;
    }
    parent[x] = findParent(parent[x]);
    return parent[x];
}

function union(x, y) {
    let xParent = findParent(x);
    let yParent = findParent(y);
    if (xParent === yParent) {
        return false;
    } else {
        if (cycles.includes(xParent)) {
            parent[yParent] = xParent;
        } else {
            parent[xParent] = yParent;
        }
        return true;
    }
}
while (true) {
    let [n, m] = input[idx++].split(" ").map(Number);
    if (n == 0 && m == 0) {
        break;
    }

    let ans = 0;
    for (let i = 1; i <= n; i++) {
        parent[i] = i;
    }
    cycles = [];
    for (let i = 0; i < m; i++) {
        let [x, y] = input[idx++].split(" ").map(Number);
        if (!union(x, y)) {
            cycles.push(findParent(x, parent[x]));
        }
    }
    for (let i = 1; i <= n; i++) {
        if (parent[i] === i && !cycles.includes(i)) {
            ans++;
        }
    }
    if (ans === 0) {
        console.log(`Case ${count++}: No trees.`);
    } else if (ans == 1) {
        console.log(`Case ${count++}: There is one tree.`);
    } else {
        console.log(`Case ${count++}: A forest of ${ans} trees.`);
    }
}
