const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');

const n = +input[0];
for (let i = 1; i <= n; i++) {
  const str = input[i].split('');
  checkContact(str);
}

function checkContact(str) {
  let index = 0;
  let answer = 'YES';

  while (index < str.length) {
    if (str[index] === '0') {
      if (str[index + 1] !== '1') {
        answer = 'NO';
        break;
      }
      index += 2;
    } else if (str[index] === '1') {
      if (str[index + 1] === '0' && str[index + 2] === '0') {
        index += 3;
        while (index < str.length) {
          if (str[index] === '0') {
            index += 1;
          } else {
            break;
          }
        }

        if (str[index] !== '1') {
          answer = 'NO';
        }
        index += 1;
        while (index < str.length) {
          if (
            (str[index] === '1' && str[index + 1] === '0' && str[index + 2] === '0') ||
            str[index] === '0'
          ) {
            break;
          }
          index += 1;
        }
      } else {
        answer = 'NO';
        break;
      }
    }
  }
  console.log(answer);
}
