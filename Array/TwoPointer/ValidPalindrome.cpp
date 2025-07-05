/*
Leetcode Valid Palindrome
Problem Link: https://leetcode.com/problems/valid-palindrome
Time Complexity: O(n)
Input: "A man, a plan, a canal: Panama"
// Output: true
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end])) end--;

            char leftChar = tolower(s[start]);// as toLower taking time to execute , instead of writing in if condition we are storing it in variable
            char rightChar = tolower(s[end]);

            if (leftChar != rightChar) return false;

            start++;
            end--;
        }

        return true;
    }
};