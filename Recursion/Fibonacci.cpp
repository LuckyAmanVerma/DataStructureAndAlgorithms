/*
Input = [0, 1, 1, 2, 3, 5, 8, 13, 21]
Output = 21
// Fibonacci series using recursion
// Time Complexity: O(2^n) - Exponential time complexity due to the recursive
*/

class Solution {
public:             
    int fib(int n) {
        if (n <= 1) {
            return n; // Base case: fib(0) = 0, fib(1) = 1
        }
        return fib(n - 1) + fib(n - 2); // Recursive case
    }
};

/*
Using Dynamic Programming to optimize the Fibonacci series
// Time Complexity: O(n) - Linear time complexity due to memoization    
*/

class Solution {
public:             
    int fib(int n) {
        if (n <= 1) {
            return n; // Base case: fib(0) = 0, fib(1) = 1
        }
        vector<int> dp(n+1);
        dp[0] = 0; // fib(0) = 0
        dp[1] = 1; // fib(1) = 1
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Fill the dp array
        } 
        return dp[n - 1]; // Return the nth Fibonacci number
    }
};