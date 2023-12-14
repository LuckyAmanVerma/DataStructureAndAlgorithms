function longestSubstring(string) {
    let newString = '';
    let longest = '';

    for (let i = 0; i < string.length; i++) {
        if (newString.includes(string[i])) {
            if (newString.length > longest.length) {
                longest = newString;
            }
            newString = newString.slice(newString.indexOf(string[i]) + 1);
        }
        newString += string[i];
    }

    if (newString.length > longest.length) {
        longest = newString;
    }

    console.log(longest);
}

let string = 'abcabdffecd';
longestSubstring(string);
