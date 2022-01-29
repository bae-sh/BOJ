let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");
let N = +input[0];
let list = input[1].split(" ");

let min = false;
let max = false;
const minNum = (arr, count) => {
    if (min) return;
    if (count === N) {
        let str = "";
        arr.forEach((e) => {
            str += e;
        });
        min = true;
        console.log(str);
        return;
    }
    for (let i = 0; i < 10; i++) {
        if (!arr.includes(i)) {
            if (count === -1) {
                arr.push(i);
                minNum(arr, count + 1);
                arr.pop();
            } else {
                if (list[count] === "<" && arr[arr.length - 1] < i) {
                    arr.push(i);
                    minNum(arr, count + 1);
                    arr.pop();
                } else if (list[count] === ">" && arr[arr.length - 1] > i) {
                    arr.push(i);
                    minNum(arr, count + 1);
                    arr.pop();
                }
            }
        }
    }
};
const maxNum = (arr, count) => {
    if (max) return;
    if (count === N) {
        let str = "";
        arr.forEach((e) => {
            str += e;
        });
        max = true;
        console.log(str);
        return;
    }
    for (let i = 9; i >= 0; i--) {
        if (!arr.includes(i)) {
            if (count === -1) {
                arr.push(i);
                maxNum(arr, count + 1);
                arr.pop();
            } else {
                if (list[count] === "<" && arr[arr.length - 1] < i) {
                    arr.push(i);
                    maxNum(arr, count + 1);
                    arr.pop();
                } else if (list[count] === ">" && arr[arr.length - 1] > i) {
                    arr.push(i);
                    maxNum(arr, count + 1);
                    arr.pop();
                }
            }
        }
    }
};
maxNum([], -1);
minNum([], -1);
