/**
 * Using Recursion
 * @param {string} s
 * @return {string}


 */
var longestPalindrome = function(str, left = 0, right = undefined, perm = '') {
    if (str.length == 0) {
        return '';
    }

    if (right === undefined) {
        right = str.length - 1;
    }
    if(left>str.length-1 || right>str.length-1){
        return perm;
    }

    if (left === right) {
        if(str[left].length>perm.length)
        return longestPalindrome(str, left+1,str.length-1, str[left]);
        else
         return longestPalindrome(str, left+1,str.length-1, perm);
    }
  
    

    if (left < right) {
        if (str[left] == str[right]) {
            let newString = str.substring(left, right + 1);
            if (isPalindrome(newString) && newString.length > perm.length) {
                perm = newString;
            }
        } 
        return longestPalindrome(str, left, right - 1, perm);
        
    }
};

function isPalindrome(str) {
    for (let left = 0, right = str.length - 1; left < right; left++, right--) {
        if (str[left] !== str[right]) {
            return false;
        }
    }
    return true;
}

const startTime = new Date().getTime();
console.log(longestPalindrome("levelnoonradar"));
const endTime = new Date().getTime();
console.log(endTime-startTime+' ms');








