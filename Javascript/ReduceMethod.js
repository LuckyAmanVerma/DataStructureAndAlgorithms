const people = [
  { name: "Aman", city: "Indore" },
  { name: "Rahul", city: "Delhi" },
  { name: "Ravi", city: "Indore" },
];

const groupByCity = people.reduce((acc, p) => {
  acc[p.city] = acc[p.city] || [];
  acc[p.city].push(p);
  return acc;
}, {});


const arr = [1, [2, [3, 4]]];

const flatten = (arr) =>
  arr.reduce(
    (acc, cur) =>
      acc.concat(Array.isArray(cur) ? flatten(cur) : cur),
    []
  );

flatten(arr);
// [1, 2, 3, 4]
