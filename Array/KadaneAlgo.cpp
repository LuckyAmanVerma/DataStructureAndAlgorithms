/*
Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
This code implements Kadane's Algorithm to find the maximum subarray sum.
Time Complexity: O(n)
Space Complexity: O(1)  
This algorithm works by iterating through the array and maintaining two variables:
*/
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