let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let [S, T] = input;
let idx = T.length - 1;
while (S.length !== T.length) {
    if (T[idx] === "A") {
        T = T.substring(0, idx);
    } else {
        T = T.substring(0, idx);
        T = T.split("").reverse().join("");
    }
    idx -= 1;
}
if (S === T) {
    console.log(1);
} else {
    console.log(0);
}
