function calculator() {
  let value;

  const api = {
    sum(a) {
      return b => {
        value = a + b;
        return api;
      };
    },

    multiply(a) {
      return b => {
        value *= b;
        return api;
      };
    },

    subtract(a) {
      return b => {
        value -= b;
        return api;
      };
    },

    valueOf() {
      return value;
    }
  };

  return api;
}

console.log(calculator().sum(5)(3).valueOf()); // Output: 12
console.log(calculator().sum(10)(20).subtract(5)(0).multiply(3)(1).valueOf()); // Output: 75
console.log(calculator().sum(1)(2).sum(3)(4).valueOf()); // Output: 7