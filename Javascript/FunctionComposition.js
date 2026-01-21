const pipe = (...fns) => {
  return (value) =>
    fns.reduce((acc, fn) => fn(acc), value);
}; 

compose(f, g)(x); // f(g(x))
pipe(f, g)(x);    // g(f(x))



const compose = (...fns) => {
  return (value) =>
    fns.reduceRight((acc, fn) => fn(acc), value);
};
