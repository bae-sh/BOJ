var fs = require("fs");
var input = fs.readFileSync("input.txt").toString().split("\n");
const [N, M] = input[0].split(" ").map((v) => +v);
let list = [];
let bag = [];
let maxWeight = 1000000;
let ans = [];
let num = 0;
let maxValue = 0;
for (let i = 1; i <= N; i++) {
    const [w, v] = input[i].split(" ").map((v) => +v);
    list.push([w, v]);
}
for (let i = N + 1; i < N + M + 1; i++) {
    bag.push(+input[i]);
}
for (let i = 0; i <= N; i++) {
    ans.push([]);
    for (let j = 0; j <= maxWeight; j++) {
        ans[i][j] = 0;
    }
}
for (let i = 0; i < N; i++) {
    const [w, v] = list[i];
    for (let j = 0; j <= maxWeight; j++) {
        if (w <= j) {
            ans[i + 1][j] = Math.max(ans[i][j], ans[i][j - w] + v);
        } else {
            ans[i + 1][j] = ans[i][j];
        }
    }
}
for (let i = 1; i < maxWeight; i++) {
    ans[N][i] = Math.max(ans[N][i], ans[N][i - 1]);
}
for (let i = 0; i < M; i++) {
    const w = bag[i];
    const curValue = ans[N][w] / w;
    if (curValue > maxValue) {
        maxValue = curValue;
        num = i + 1;
    }
}
console.log(num);
