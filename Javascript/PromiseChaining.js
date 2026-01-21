const promise1 = new Promise((resolve, reject) => {
  resolve('promise resolved');
  setTimeout(()=>reject('Reject'),0);
  //reject('promise reject')
  console.log('inside promise');
});

promise1
  .then((res) => console.log('first then'))
  .catch((e) => console.log('first catch'))
  .then((res) => console.log('second then'))
  .then((res) => console.log('third then'))
  .catch((e) => console.log('second catch'))
  .finally(e=>console.log('inside finally'))
  .then((res) => console.log('fourth then'));


  // Prepare the list of coding question asked during interview related to Promise chaining and Promise  methods in JavaScript.
// 1. Explain Promise chaining in JavaScript with an example.
// 2. How does error handling work in Promise chaining?
// 3. What is the difference between .then() and .catch() in Promise chaining?
// 4. Can you chain multiple .then() methods together? Provide an example.
// 5. How can you return a value from one .then() to the next in the chain?
// 6. What happens if a Promise in the chain is rejected? How can you handle it?
// 7. Explain the use of .finally() in Promise chaining.
// 8. How can you use async/await syntax to achieve similar functionality as Promise chaining?
// 9. What are some common pitfalls to avoid when using Promise chaining?
// 10. Can you mix .then() and async/await in the same function? Provide an example.
// 11. How do Promise.all() and Promise.race() work in conjunction with Promise chaining?


// Answers:// 1. Promise chaining allows you to execute multiple asynchronous operations in sequence. Each .then() returns a new Promise, allowing for further chaining.
// Example:
// fetchData()
//   .then(data => processData(data))
//   .then(processedData => saveData(processedData))
//   .catch(error => console.error('Error:', error));
// 2. In Promise chaining, if any Promise is rejected, the control jumps to the nearest .catch() block. You can handle errors at any point in the chain.
// 3. .then() is used to handle resolved Promises, while .catch() is specifically for handling rejected Promises.
// 4. Yes, you can chain multiple .then() methods together.
// Example:
// fetchData()
//   .then(data => processData(data))
//   .then(processedData => saveData(processedData));
// 5. You can return a value from one .then() to the next by simply returning it.
// Example:
// fetchData()
//   .then(data => {
//     return processData(data);
//   })
//   .then(processedData => {
//     console.log(processedData);
//   });
// 6. If a Promise in the chain is rejected, the control jumps to the nearest .catch() block. You can handle it by adding a .catch() at the end of the chain.
// 7. .finally() is used to execute code after the Promise is settled, regardless of whether it was resolved or rejected.
// Example:
// fetchData()
//   .then(data => processData(data))
//   .catch(error => console.error('Error:', error))
//   .finally(() => console.log('Operation completed'));
// 8. You can use async/await to achieve similar functionality as Promise chaining by using the await keyword to wait for Promises to resolve.
// Example:
// async function fetchDataAndProcess() {
//   try {
//     const data = await fetchData();
//     const processedData = await processData(data);
//     await saveData(processedData);
//   } catch (error) {
//     console.error('Error:', error);
//   }
// }
// 9. Common pitfalls include not returning Promises in .then() handlers, which can break the chain, and not handling errors properly.
// 10. Yes, you can mix .then() and async/await in the same function.
// Example:
// async function fetchDataAndProcess() {
//   const data = await fetchData();
//   processData(data).then(processedData => {
//     console.log(processedData);
//   });
// }
// 11. Promise.all() waits for all Promises to resolve and returns an array of results, while Promise.race() returns the result of the first settled Promise. They can be used in Promise chaining to handle multiple asynchronous operations concurrently.
    