const debounce = (fn, delay) => {
  let timer;
  return function(...args) {
    clearTimeout(timer);
    timer = setTimeout(() => fn.apply(this, args), delay);
  };
};


import React, { useState, useEffect } from "react";

// debounce utility
const debounce = (fn, delay) => {
  let timer;
  return (...args) => {
    clearTimeout(timer);
    timer = setTimeout(() => fn(...args), delay);
  };
};

export default function SearchBox() {
  const [query, setQuery] = useState("");

  // debounced API call
  const debouncedApiCall = React.useMemo(
    () =>
      debounce((searchTerm) => {
        console.log("Calling API with:", searchTerm);
        // Example: fetch(`https://api.example.com/search?q=${searchTerm}`)
      }, 2000),
    []
  );

  useEffect(() => {
    if (query) {
      debouncedApiCall(query);
    }
  }, [query, debouncedApiCall]);

  return (
    <div>
      <input
        type="text"
        placeholder="Type to search..."
        value={query}
        onChange={(e) => setQuery(e.target.value)}
      />
    </div>
  );
}