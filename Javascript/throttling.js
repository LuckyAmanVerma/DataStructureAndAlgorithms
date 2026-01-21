const throttle = (fn, time) => {
  let timer = null;
  return function(...args) {
    if (timer) return;
    const result = fn.apply(this, args);   // preserve this + capture return
    timer = setTimeout(() => timer = null, time);
    return result;
  };
};

// Example usage:
const logMessage = (message) => {
    console.log(message);
};