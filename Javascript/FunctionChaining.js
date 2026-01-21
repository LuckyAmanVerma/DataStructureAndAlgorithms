function multiplyChain(x) {
    let product = x;

    function inner(y) {
        if (y === undefined) {
            return product;
        }
        product *= y;
        return inner;
    }

    return inner;
}

console.log(multiplyChain(5)(4)());      // Output: 20
console.log(multiplyChain(5)(4)(4));   // Output: 80
console.log(multiplyChain(2)(3)(4)());   // Output: 24

const calc = {
  value: 0,
  add(n) {
    this.value += n;
    return this;
  },
  sub(n) {
    this.value -= n;
    return this;
  },
  valueOf() {
    return this.value;
  }
};

;
console.log(calc.add(5).sub(2).add(10).valueOf());

