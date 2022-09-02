const counter = (function () {
  let count = 0;
  function change(val) {
    count += val;
  }
  return {
    increase: function () {
      change(+1);
    },
    decrease: function () {
      change(-1);
    },
    value: function () {
      return count;
    },
  };
})();

console.log(counter.value());
counter.increase();
console.log(counter.value());
