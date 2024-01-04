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
