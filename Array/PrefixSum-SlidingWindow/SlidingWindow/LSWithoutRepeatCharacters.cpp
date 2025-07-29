/*
Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
Input: "abcabcbb"
Output: 3 (The longest substring is "abc")
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int withoutRepeat(string str) {
    int n = str.size();
    if (n == 0) return 0;
    unordered_map<char, int> m;
    int i = 0, j = 0, ans = 0;

    while (j < n) {
        m[str[j]]++; // Always add current character

        // CASE 1: No repeat yet; keep expanding window
        if (m[str[j]] == 1) {
            ans = max(ans, j - i + 1); // update answer
            j++;
        }
        // CASE 2: Duplicate found; shrink window until valid
        else if (m[str[j]] > 1) {
            while (m[str[j]] > 1) {
                m[str[i]]--;
                i++;
            }
            // After shrinking, expand again in next loop
            j++;
        }
        // (You could add a CASE 3 for other situations, but for this problem, CASE 1 and 2 suffice)
    }
    return ans;
}


int main() {
    string str = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " 
         << withoutRepeat(str) << endl;
    return 0;
}   


