const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const [N, M, R] = input.shift().split(' ').map(Number);
let arr = [];

for (let i = 0; i < N; i++) {
  const temp = input.shift().split(' ').map(Number);
  arr.push(temp);
}
input
  .shift()
  .split(' ')
  .forEach(r => {
    arr = rotate(r);
  });

for (let i = 0; i < arr.length; i++) {
  console.log(arr[i].join(' '));
}

function rotate(num) {
  const nextArr = [];
  if (num === '1') {
    return arr.reverse();
  } else if (num === '2') {
    for (let i = 0; i < arr.length; i++) {
      nextArr.push(arr[i].reverse());
    }
  } else if (num === '3') {
    for (let i = 0; i < arr[0].length; i++) {
      const temp = [];
      for (let j = arr.length - 1; j >= 0; j--) {
        temp.push(arr[j][i]);
      }
      nextArr.push(temp);
    }
  } else if (num === '4') {
    for (let i = arr[0].length - 1; i >= 0; i--) {
      const temp = [];
      for (let j = 0; j < arr.length; j++) {
        temp.push(arr[j][i]);
      }
      nextArr.push(temp);
    }
  } else if (num === '5') {
    for (let i = arr.length / 2; i < arr.length; i++) {
      nextArr.push(arr[i].slice(0, arr[i].length / 2));
    }
    for (let i = arr.length / 2; i < arr.length; i++) {
      nextArr.push(arr[i].slice(arr[i].length / 2));
    }
    for (let i = 0; i < arr.length / 2; i++) {
      nextArr[i].push(...arr[i].slice(0, arr[i].length / 2));
    }
    for (let i = 0; i < arr.length / 2; i++) {
      nextArr[arr.length / 2 + i].push(...arr[i].slice(arr[i].length / 2));
    }
  } else if (num === '6') {
    for (let i = 0; i < arr.length / 2; i++) {
      nextArr.push(arr[i].slice(arr[i].length / 2));
    }
    for (let i = 0; i < arr.length / 2; i++) {
      nextArr.push(arr[i].slice(0, arr[i].length / 2));
    }
    for (let i = arr.length / 2; i < arr.length; i++) {
      nextArr[i - arr.length / 2].push(...arr[i].slice(arr[i].length / 2));
    }
    for (let i = arr.length / 2; i < arr.length; i++) {
      nextArr[i].push(...arr[i].slice(0, arr[i].length / 2));
    }
  }
  return nextArr;
}
