let funcs = [];

for (let i = 0; i < 3; i++) {
  funcs[i] = function () {
    return i;
  };
}

for (let i = 0; i < 3; i++) {
  console.log(funcs[i]());
}
