let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let a = +input[0];
let b = +input[1];
console.log((a - b) / 2 + b);
console.log((a - b) / 2);
