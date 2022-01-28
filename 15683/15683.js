let fs = require("fs");
let input = fs.readFileSync("input.txt").toString().split("\n");

let [N, M] = input[0].split(" ").map((v) => +v);
let office = [];
let cctv = [];
let ans = 987654321;
for (let i = 0; i < N; i++) {
    let temp = input[1 + i].split(" ").map((v) => +v);
    office.push(temp);
    temp.forEach((v, index) => {
        if (1 <= v && v <= 5) {
            cctv.push([v, i, index]);
        }
    });
}
const leftFill = (x, y, arr) => {
    let nx = x;
    let ny = y - 1;
    while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[nx][ny] === 6) break;
        if (arr[nx][ny] === 0) {
            arr[nx][ny] = -1;
        }
        ny -= 1;
    }
};
const upFill = (x, y, arr) => {
    let nx = x - 1;
    let ny = y;
    while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[nx][ny] === 6) break;
        if (arr[nx][ny] === 0) {
            arr[nx][ny] = -1;
        }
        nx -= 1;
    }
};
const downFill = (x, y, arr) => {
    let nx = x + 1;
    let ny = y;
    while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[nx][ny] === 6) break;
        if (arr[nx][ny] === 0) {
            arr[nx][ny] = -1;
        }
        nx += 1;
    }
};
const rightFill = (x, y, arr) => {
    let nx = x;
    let ny = y + 1;
    while (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (arr[nx][ny] === 6) break;
        if (arr[nx][ny] === 0) {
            arr[nx][ny] = -1;
        }
        ny += 1;
    }
};

const arrCopy = (arr) => {
    return arr.map((v) => v.slice());
};
const arrCheck = (arr) => {
    let count = 0;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (arr[i][j] == 0) count++;
        }
    }
    return count;
};
const brute = (count, arr) => {
    if (count >= cctv.length) {
        let temp = arrCheck(arr);
        ans = Math.min(ans, temp);
        return;
    }
    let [c, x, y] = cctv[count];
    if (c == 1) {
        let temp = arrCopy(arr);
        leftFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        upFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        downFill(x, y, temp);
        brute(count + 1, temp);
    } else if (c == 2) {
        let temp = arrCopy(arr);
        leftFill(x, y, temp);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        upFill(x, y, temp);
        downFill(x, y, temp);
        brute(count + 1, temp);
    } else if (c == 3) {
        let temp = arrCopy(arr);
        leftFill(x, y, temp);
        upFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        upFill(x, y, temp);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        rightFill(x, y, temp);
        downFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        downFill(x, y, temp);
        leftFill(x, y, temp);
        brute(count + 1, temp);
    } else if (c == 4) {
        let temp = arrCopy(arr);
        leftFill(x, y, temp);
        upFill(x, y, temp);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        downFill(x, y, temp);
        upFill(x, y, temp);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        leftFill(x, y, temp);
        downFill(x, y, temp);
        rightFill(x, y, temp);
        brute(count + 1, temp);
        temp = arrCopy(arr);
        leftFill(x, y, temp);
        upFill(x, y, temp);
        downFill(x, y, temp);
        brute(count + 1, temp);
    } else if (c == 5) {
        let temp = arrCopy(arr);
        leftFill(x, y, temp);
        upFill(x, y, temp);
        rightFill(x, y, temp);
        downFill(x, y, temp);
        brute(count + 1, temp);
    }
};
brute(0, office);
console.log(ans);
