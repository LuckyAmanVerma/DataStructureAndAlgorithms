let longestSubstring = ""; // Global variable to track the longest substring

function recursion(str) {
    if (str.length == 0) {
        return;
    }

    for (let i = 0; i < str.length; i++) {
        let newString = str.substring(0, i) + str.substring(i + 1);
        if (isPalindrome(newString) && newString.length > longestSubstring.length) {
            longestSubstring = newString;
        }
        recursion(newString);
    }
}

function isPalindrome(str) {
    for (let left = 0, right = str.length - 1; left < right; left++, right--) {
        if (str[left] !== str[right]) {
            return false;
        }
    }
    return true;
}


recursion("cbbd");
console.log("Longest Palindromic Substring:", longestSubstring);
