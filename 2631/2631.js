var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split("\n");
const N = Number(input[0]);
let list = [];
let dp = [];
for (let i = 0; i < N; i++) {
    let x = input[i + 1];
    list.push(Number(x));
    dp[i] = 1;
}

for (let i = 0; i < N; i++) {
    let cur = list[i];
    for (let j = 0; j < i; j++) {
        if (list[j] < cur && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
        }
    }
}
let ans = 0;
dp.forEach((value) => {
    ans = Math.max(ans, value);
});
console.log(N - ans);
