var fs = require("fs"); //"/dev/stdin"
var input = fs.readFileSync("input.txt").toString().split("\n");
let n = input[0];
let distance = input[1].split(" ").map((v) => BigInt(v));
let costs = input[2].split(" ").map((v) => BigInt(v));
let minCost = costs[0];
let ans = 0n;
for (let i = 0; i < distance.length; i++) {
    let dis = distance[i];
    ans += dis * minCost;
    minCost = minCost > costs[i + 1] ? costs[i + 1] : minCost;
}
console.log(String(ans));
