let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let N = +input[0];
let check = new Array(N + 1).fill(false);
let arr = [0];
let ans = [];

for (let i = 1; i <= N; i++) {
    let x = +input[i];
    arr.push(x);
    if (x == i) {
        check[i] = true;
    }
}

function checkCycle(x, visit) {
    if (check[x]) return false;
    if (arr[x] === visit[0]) {
        check[x] = true;
        return true;
    }
    if (visit.includes(arr[x])) return false;
    visit.push(arr[x]);
    check[x] = checkCycle(arr[x], visit);
    return check[x];
}

for (let i = 1; i <= N; i++) {
    checkCycle(i, [i]);
}

for (let i = 1; i <= N; i++) {
    if (check[i]) {
        ans.push(i);
    }
}

console.log(ans.length);
ans.map((number) => {
    console.log(number);
});
