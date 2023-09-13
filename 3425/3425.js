//ERROR : 숫자가 부족해서 연산 못할떄, 0으로 나눌때(DIV,MOD), 결과가 10^9넘을때
const fs = require('fs');
const input = fs.readFileSync('input.txt').toString().split('\n');
let index = 0;
while (true) {
  if (input[index] === 'QUIT') break;
  const orders = [];
  while (true) {
    if (input[index] === 'END') {
      index += 1;
      break;
    }
    orders.push(input[index++]);
  }

  const N = +input[index++];
  for (let i = 0; i < N; i++) {
    const num = +input[index++];
    const stack = [num];
    let error = false;
    for (let i = 0; i < orders.length; i++) {
      if (!cal(orders[i], stack)) {
        error = true;
        break;
      }
    }
    if (error || stack.length !== 1) {
      console.log('ERROR');
    } else {
      if (stack[0] === -0) {
        console.log(Math.abs(stack[0]));
      } else {
        console.log(stack[0]);
      }
    }
  }
  index += 1;
  console.log();
}

function cal(order, stack) {
  const [command, x] = order.split(' ');
  if (command === 'NUM') {
    stack.push(+x);
    return true;
  }
  if (stack.length === 0) return false;

  const num1 = stack.pop();
  if (command === 'POP') {
    return true;
  }
  if (command === 'INV') {
    stack.push(-num1);
    return true;
  }
  if (command === 'DUP') {
    stack.push(num1, num1);
    return true;
  }

  if (stack.length === 0) return false;
  if (command === 'SWP') {
    const num2 = stack.pop();
    stack.push(num1, num2);
    return true;
  }
  if (command === 'ADD') {
    const num2 = stack.pop();
    stack.push(num1 + num2);
    if (Math.abs(num1 + num2) > 10 ** 9) return false;
    return true;
  }
  if (command === 'SUB') {
    const num2 = stack.pop();
    stack.push(num2 - num1);
    if (Math.abs(num2 - num1) > 10 ** 9) return false;
    return true;
  }
  if (command === 'MUL') {
    const num2 = stack.pop();
    stack.push(num2 * num1);
    if (Math.abs(num2 * num1) > 10 ** 9) return false;
    return true;
  }

  if (num1 === 0) return false;
  if (command === 'DIV') {
    const num2 = stack.pop();
    let ng = 0;
    num1 < 0 && ng++;
    num2 < 0 && ng++;
    ng = ng === 1 ? -1 : 1;
    stack.push(Math.floor(Math.abs(num2) / Math.abs(num1)) * ng);
    return true;
  }
  if (command === 'MOD') {
    const num2 = stack.pop();
    stack.push(num2 % num1);
    return true;
  }
}
