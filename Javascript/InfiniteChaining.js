function sum(a) {
  let total = a;

  function inner(b) {
    total += b;
    return inner;
  }

  inner.valueOf = function () {
    return total;
  };

  inner.toString = function () {
    return String(total);
  };

  return inner;
}

function multiply(a) {
  let total = a;

  function inner(b) {
    total *= b;
    return inner;
  }

  inner.valueOf = function () {
    return total;
  };

  inner.toString = function () {
    return String(total);
  };

  return inner;
}

function subtract(a) {
  let total = a;

  function inner(b) {
    total -= b;
    return inner;
  }

  inner.valueOf = function () {
    return total;
  };

  inner.toString = function () {
    return String(total);
  };

  return inner;
}


console.log(sum(1)(2)(3).valueOf()); // Output: 6
console.log(sum(5)(10)(15)(20).toString()); // Output: 50


function sum(a) {
  let total = a;

  return function next(b) {
    if (b === undefined) return total;
    total += b;
    return next;
  };
}

sum(1)(2)(3)();

