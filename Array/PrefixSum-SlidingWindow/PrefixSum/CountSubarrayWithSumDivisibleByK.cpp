/*
Input:
nums = [4, 5, 0, -2, -3, 1]
k = 5
Output:-7
Explanation
The 7 valid subarrays are those whose sums give a remainder 0 when divided by 3:
- [1, 2] → sum = 3
- [1, 2, 3] → sum = 6
- [2, 3, 4] → sum = 9
- [3] → sum = 3
- [3, 4, 5] → sum = 12
- [4, 5] → sum = 9
- [1, 2, 3, 4, 5] → sum = 15

How It Works
- Compute the running sum modulo k at each index:
mod = (current_sum % k + k) % k  
- Use a hash map to count how many times each mod value has appeared so far.
- For each new mod, the number of previous occurrences of the same mod gives the count of subarrays ending here whose sum is divisible by k.
- Accumulate these counts to get the final answer.
nums = [4, 5, 0, -2, -3, 1]
k = 5
Output:-7
*/

int CountSubarraySumDivisibleByK(vector<int> nums,int k) {
    int sum=0;
    int n=nums.size();
    int start=0;
    int end=n;
    int count=0;
    
}