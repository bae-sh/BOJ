let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let n = +input;
if (n >= 1023) {
    console.log(-1);
} else {
    let dp = new Array(1025).fill(0);
    let q = [];
    let idx = 0;
    for (let i = 1; i < 10; i++) {
        q.push(i);
        dp[++idx] = i;
    }

    while (q.length !== 0 || idx < n) {
        let num = q.shift();
        let digit = num % 10;
        for (let i = 0; i < digit; i++) {
            let newNumber = num * 10 + i;
            dp[++idx] = newNumber;
            q.push(newNumber);
        }
    }
    console.log(dp[n]);
}
