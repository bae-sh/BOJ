let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let T = +input[0];
let k = +input[1];
let dp = new Array(10001).fill(0);
dp[0] = 1;
for (let i = 0; i < k; i++) {
    let [x, y] = input[2 + i].split(" ").map(Number);
    for (let j = T; j >= 1; j--) {
        for (let k = 1; k <= y; k++) {
            if (j - x * k < 0) break;
            dp[j] += dp[j - x * k];
        }
    }
}
console.log(dp[T]);
