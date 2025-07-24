/*
Problem: Given an array of integers and a number k, find the maximum sum of a subarray of size k.
Approach: Use the sliding window technique to maintain the sum of the current window of size k
and update the maximum sum found so far.
Example: For the array [2, 1, 5, 1, 3, 2] and k = 3, the maximum sum of a subarray of size 3 is 9 (subarray [5, 1, 3]).
Time Complexity: O(n), where n is the number of elements in the array.
*/

#include<iostream>
#include<vector>
 using namespace std;

int maxSumSubArray(vector<int> array,int k){
 int asize = array.size();
 int left,right=0;
 int sum=0;
 int max_sum=INT_MIN;
 while(right<asize){
    // keep track of sum untill window size meet
    sum+=array[right];
    if(right-left+1<k){
        right++;
    }
    else if(right-left+1==k){
        // once size meet , we set the max value and then slide the window , 
        if(sum>max_sum){
            cout<<endl<<"Max Sum Path ";
            for(int i=left;i<=right;i++){
                cout<<array[i]<<" "<<endl;
            }
        }
    max_sum= max(max_sum,sum);
     sum-=array[left];
    left++; right++;
    }
    
 }
 return max_sum;
}

int main (){
    vector<int> array={2, 1, 5, 1, 3, 2};
    cout<<"max sub array"<<maxSumSubArray(array,3);
}