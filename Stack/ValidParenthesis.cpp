/*
https://leetcode.com/problems/valid-parentheses/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"

- We scan the string one character at a time.
- If it’s an opening bracket ((, [, {), we push it onto our stack.
- If it’s a closing bracket (), ], }), we:
- Check if the stack is empty—if so, there’s nothing to match, so it’s invalid.
- Otherwise, compare the stack’s top bracket with the current one; if they form a matching pair, pop the stack; if not, it’s invalid.
- After processing every character, the string is valid only if the stack is empty (every opening had a matching closing).

*/

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int length = s.length();
        for(i=0; i < length; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if(st.empty()) {
                return false; // If stack is empty, no opening bracket to match
            }
            else if ((s[i] == ')' && st.top() == '(') ||
                     (s[i] == '}' && st.top() == '{') ||
                     (s[i] == ']' && st.top() == '[')) {
                st.pop(); // If current closing matches the top of the stack, pop it
            }
            else {
                return false; // Mismatched closing bracket
            }
             
    }
        return st.empty(); // If stack is empty, all brackets matched correctly
}
};