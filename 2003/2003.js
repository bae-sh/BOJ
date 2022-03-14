let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [N, M] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);
let ans = 0;
let q = [];
let temp = 0;

for (let i = 0; i < N; i++) {
    q.push(arr[i]);
    temp += arr[i];
    while (!q.length !== 0 && M < temp) {
        let cur = q.shift();
        temp -= cur;
    }
    if (temp === M) {
        ans++;
    }
}

console.log(ans);
