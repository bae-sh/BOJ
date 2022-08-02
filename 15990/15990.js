let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");

let N = +input[0];
let dp = Array.from({ length: 100001 }, () => [0, 0, 0, 0]);
let mod = 1000000009;
dp[1][1] = 1;
dp[2][2] = 1;
dp[3][1] = 1;
dp[3][2] = 1;
dp[3][3] = 1;

for (let i = 4; i <= 100000; i++) {
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
}

for (let i = 0; i < N; i++) {
    let x = input[i + 1];
    console.log((dp[x][1] + dp[x][2] + dp[x][3]) % mod);
}
