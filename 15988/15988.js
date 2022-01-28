let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let idx = 0;
let T = +input[idx++];
let dp = [0, 1, 2, 4];

const MOD = 1000000009;
for (let i = 4; i <= 1000000; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
}
while (T--) {
    let N = +input[idx++];
    console.log(dp[N]);
}
