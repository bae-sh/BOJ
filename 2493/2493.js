var fs = require("fs");
var input = fs.readFileSync("input.txt").toString().split("\n");
const N = Number(input[0]);
let li = input[1].split(" ");
let vec = [];
let ans = [];
for (let i = 0; i < N; i++) {
    vec.push(Number(li[i]));
    ans.push(0);
}
let st = [];
while (vec.length !== 0) {
    let count = vec.length;
    let cur = vec.pop();
    while (st.length !== 0) {
        let send = st.pop();
        if (send.value <= cur) {
            ans[send.num - 1] = count;
        } else {
            st.push(send);
            break;
        }
    }
    st.push({ num: count, value: cur });
}
let str = "";
for (let i = 0; i < N; i++) {
    str += ans[i];
    str += " ";
}
console.log(str);
