var isPalindrome = function(s) {
  let left = 0;
  let right = s.length - 1;

  while (left < right) {
    while (left < right && !isAlphaNum(s[left])) left++;
    while (left < right && !isAlphaNum(s[right])) right--;

    if (s[left].toLowerCase() !== s[right].toLowerCase()) {
      return false;
    }

    left++;
    right--;
  }

  return true;
};

function isAlphaNum(char) {
  return /^[a-z0-9]$/i.test(char);
}
console.log(isPalindrome("A man, a plan, a canal: Panama")); // Output: true