const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [r, c, k] = input[0].split(' ').map(Number);
let array = Array.from({ length: 100 }, () => new Array(100).fill(0));
for (let i = 0; i < 3; i++) {
  const temp = input[i + 1].split(' ').map(Number);
  for (let j = 0; j < 3; j++) {
    array[i][j] = temp[j];
  }
}

function checkArrLen() {
  let [rlen, clen] = [0, 0];
  for (let i = 0; i < 100; i++) {
    let temp = 0;
    for (let j = 0; j < array[i].length; j++) {
      if (array[i][j] === 0) break;
      temp += 1;
    }
    clen = Math.max(clen, temp);
  }
  for (let i = 0; i < 100; i++) {
    let temp = 0;
    for (let j = 0; j < 100; j++) {
      if (array[j][i] === 0) break;
      temp += 1;
    }
    rlen = Math.max(rlen, temp);
  }
  return rlen >= clen;
}
function arrCopy(arr, way) {
  //rCal
  array = Array.from({ length: 100 }, () => new Array(100).fill(0));
  if (way) {
    for (let i = 0; i < arr.length; i++) {
      for (let j = 0; j < arr[i].length; j++) {
        array[i][j] = arr[i][j];
      }
    }
  } else {
    for (let i = 0; i < arr.length; i++) {
      for (let j = 0; j < arr[i].length; j++) {
        array[j][i] = arr[i][j];
      }
    }
  }
}
function arrSort(arr) {
  let newArr = [];
  let temp = [];
  const obj = {};
  arr.forEach(value => {
    if (value !== 0) Object.keys(obj).includes(`${value}`) ? (obj[value] += 1) : (obj[value] = 1);
  });
  Object.keys(obj).forEach(key => {
    temp.push({ value: key, count: obj[key] });
  });
  temp.sort((a, b) => {
    if (a.count !== b.count) return a.count - b.count;
    return Number(a.value) - Number(b.value);
  });
  temp.forEach(({ value, count }) => {
    newArr.push(Number(value));
    newArr.push(count);
  });
  if (newArr.length > 100) {
    newArr = temp.slice(0, 100);
  }
  return newArr;
}

function rCal() {
  let newArr = [];
  for (let i = 0; i < array.length; i++) {
    const arr = array[i];
    let temp = arrSort(arr);
    if (temp.length > 0) newArr.push(temp);
    else break;
  }
  arrCopy(newArr, true);
}

function cCal() {
  let newArr = [];
  for (let i = 0; i < 100; i++) {
    let temp = [];
    for (let j = 0; j < 100; j++) {
      temp.push(array[j][i]);
    }
    temp = arrSort(temp);
    if (temp.length > 0) newArr.push(temp);
    else break;
  }
  arrCopy(newArr, false);
}

function Cal() {
  for (let timer = 0; timer <= 101; timer++) {
    if (array[r - 1][c - 1] === k) return timer;
    checkArrLen() ? rCal() : cCal();
  }

  return -1;
}

console.log(Cal());
