/*
Problem: Given a string and an integer k, find the length of the longest substring that contains at most k unique characters.
Approach: Use a sliding window technique with a hash map to count the characters in the current
Input: "eceba", k = 2
Output: 3 (The longest substring is "ece" or "ba") substring.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int uniqueCharacters(string str, int k) {
    int n = str.size();
    if (n == 0 || k == 0) return 0;
    unordered_map<char, int> m;
    int i = 0, j = 0, ans = 0;

    while (j < n) {
        // Expand window: add current character to map
        m[str[j]]++;

        // CASE 1: If unique chars still less than k, move right pointer
        if (m.size() < k) {
            j++;
        }
        // CASE 2: If unique chars exactly k, update answer, move right pointer
        else if (m.size() == k) {
            ans = max(ans, j - i + 1);
            j++;
        }
        // CASE 3: Unique chars more than k, shrink from left
        else {
            while (m.size() > k) {
                m[str[i]]--;
                if (m[str[i]] == 0)
                    m.erase(str[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main() {
    string str = "aabbcc";
    int k = 1;
    cout << "Length of the longest substring with at most " << k << " unique characters: " 
         << uniqueCharacters(str, k) << endl;
    return 0;
}