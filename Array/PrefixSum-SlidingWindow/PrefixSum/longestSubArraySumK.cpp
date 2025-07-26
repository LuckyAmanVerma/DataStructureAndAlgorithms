/*
 Not able to use Sliding window as input contain negative values , 
If input contains negative value , we will use prefix sum technique
Input with negative values:[1, -2, 3, 4, -5] k = 2
 Output: 3 (subarray [1, -2, 3] or [3, 4, -5] or [-2, 3, 4])
 Using Prefix Sum Technique - O(n)
*/

#include <vector>
#include<iostream>
using namespace std;

void longestSubArraySumK(vector<int> array, int k) {
    int n = array.size();
    int ans=0;
    pair<int,int> index={-1,-1};
    vector<int> prefixSum(n+1,0);
    for(int i=1;i<=n;i++){
        prefixSum[i]=prefixSum[i-1]+array[i-1];
    }

    for(int i=0;i<=n;i++){
        if(prefixSum[i]==k){ 
            if(i>ans){
                index={0,i};
            } // to check single values 
            ans=max(ans,i);
            
        }
        for(int j=i+1;j<=n;j++){  // to check n size sub array , like [1,2,3] k=5 , then o/p [2,3] length 2  
            if(prefixSum[j]-prefixSum[i]==k) {
                 if(j-i>ans) index={i,j};
                ans = max(ans,j-i);
               
                
            }
        }
    }

    cout << "Length of longest subarray with sum " << k << " is: " << ans << endl;
    cout<<index.first<<" "<<index.second; 
    
    
};

void bruteForceApproach(vector<int> array,int k){  // [1, -2, 3, 4, -5] ,2
    int size=array.size();
    int ans=0;
    
    for(int i=0;i<size;i++){
        int sum=array[i];  // Reset sum for each starting point
        if(sum == k) {     // Check single element
            ans = max(ans, 1);
        }
        for(int j=i+1;j<size;j++){
            sum += array[j];
            if(sum == k) {
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << "Length of longest subarray with sum " << k << " is: " << ans << endl;
}


int main(){
    vector<int> array={1, -2, 3, 4, -5};
    longestSubArraySumK(array,2);
}
