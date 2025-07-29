function lswithoutRepeat(str) {
    let i = 0;
    let j = 0;
    let size = str.length;
    let m = {};
    let ans = 0;

    while (j < size) {
        if (m[str[j]]) {
            m[str[j]]++;
        }
        else {
            m[str[j]] = 1;
        }

        if (m[str[j]] == 1) {
            ans = Math.max(ans, j - i + 1); // update answer
            j++;
        }

        else if (m[str[j]] > 1) {
            while (m[str[j]] > 1) {
                m[str[i]] -= 1;
                i++;
            }
            j++;
        }


    }
    console.log(ans);
}

lswithoutRepeat("abcdbaba");