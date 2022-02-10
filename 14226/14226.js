let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");

let S = +input[0];
let dp = [];
let max = 987654321;
for (let i = 0; i <= 2000; i++) {
    let temp = [];
    for (let i = 0; i <= 2000; i++) {
        temp.push(max);
    }
    dp.push(temp);
}

console.log(bfs());

function bfs() {
    let q = [[1, 0]];
    dp[1][0] = 0;
    while (q.length !== 0) {
        let [count, copy] = q.shift();
        if (count === S) {
            return dp[count][copy];
        }
        if (dp[count][count] > dp[count][copy] + 1) {
            dp[count][count] = dp[count][copy] + 1;
            q.push([count, count]);
        }
        if (count + copy <= 2000 && copy !== 0) {
            if (dp[count + copy][copy] > dp[count][copy] + 1) {
                dp[count + copy][copy] = dp[count][copy] + 1;
                q.push([count + copy, copy]);
            }
        }
        if (count - 1 >= 0) {
            if (dp[count - 1][copy] > dp[count][copy] + 1) {
                dp[count - 1][copy] = dp[count][copy] + 1;
                q.push([count - 1, copy]);
            }
        }
    }
}
