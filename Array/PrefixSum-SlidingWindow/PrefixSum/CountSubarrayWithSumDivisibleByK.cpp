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

Can 't be solve with sliding window , if it contain positive values , as we also need to backtrack
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int CountSubarraySumDivisibleByK(vector<int> nums,int k) {
    int asize=nums.size();
    int sum=0;
    int count=0;
    vector<int> ps(asize,nums[0]);
    unordered_map<int,int> m;

    for(int i=1;i<asize;i++){ //[4, 5, 0, -2, -3, 1] k=5  ps =[4, 9, 9, 7, 4, 5]
        ps[i]=ps[i-1]+nums[i];
    }

    for(int j=0;j<asize;j++) {
        if(ps[j]%k==0){
            count+=1;
        }

        int target = ps[j] % k;
        if(target < 0) {
            target += k; // Ensure target is non-negative
        }
        if(m.find(target) != m.end()) {
            count += m[target];
        }

        m[target]++;
    }

    return count;
}

int  main(){
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = CountSubarraySumDivisibleByK(nums, k);
    cout << "Count of subarrays with sum divisible by " << k << " is: " << result << endl;
    return 0;
}