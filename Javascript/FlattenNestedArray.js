const arr = [1, [2, [3, 4]]];

const flatten = (arr) =>
  arr.reduce(
    (acc, cur) =>
      acc.concat(Array.isArray(cur) ? flatten(cur) : cur),
    []
  );

flatten(arr);
// [1, 2, 3, 4]
