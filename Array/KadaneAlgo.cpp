/*
Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
This code implements Kadane's Algorithm to find the maximum subarray sum.
Time Complexity: O(n)
Space Complexity: O(1)  
This algorithm works by iterating through the array and maintaining two variables:

// For arr = [2, 3, -8, 7, -1, 2, 3]:
// Iteration details:
// i = 0: max_till_now = 2,  max_overall = 2
// i = 1: max_till_now = 5,  max_overall = 5
// i = 2: max_till_now = -3, max_overall = 5
// i = 3: max_till_now = 7,  max_overall = 7
// i = 4: max_till_now = 6,  max_overall = 7
// i = 5: max_till_now = 8,  max_overall = 8
// i = 6: max_till_now = 11, max_overall = 11
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {  
        int max_till_now =arr[0];   //2,5,0,7
        int max_overall=arr[0]; //2,5,7
        int length=arr.size();
        
        for(int i=1;i<length;i++){          //i  =0 ,1,2,3,4
           max_till_now = max(arr[i], max_till_now + arr[i]); //2,5,0,7
           max_overall = max(max_overall, max_till_now); //2,5,7 
        }
        return max_overall; //7
    }
};
int main(){
  Solution s;
  vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
  cout << s.maxSubarraySum(arr) << endl;
  return 0;
}