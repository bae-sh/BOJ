let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let N = +input[0];
let countries = input[1].split(" ").map(Number);
let maxCost = +input[2];

let l = 0;
let r = Math.max(...countries);
let ans = 0;
while (l <= r) {
    let mid = Math.floor((l + r) / 2);
    let count = 0;
    countries.map((money) => {
        if (money <= mid) {
            count += money;
        } else {
            count += mid;
        }
    });
    if (count <= maxCost) {
        l = mid + 1;
        ans = mid;
    } else {
        r = mid - 1;
    }
}
console.log(ans);
