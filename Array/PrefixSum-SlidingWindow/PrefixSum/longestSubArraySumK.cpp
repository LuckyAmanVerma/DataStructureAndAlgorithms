/*
 Not able to use Sliding window as input contain negative values , 
If input contains negative value , we will use prefix sum technique
Input with negative values:[1, -2, 3, 4, -5] k = 2
 Output: 3 (subarray [1, -2, 3] or [3, 4, -5] or [-2, 3, 4])
 Using Prefix Sum Technique - O(n)
*/

#include <vector>
#include<iostream>
#include <unordered_map>

using namespace std;

void longestSubArraySumK(vector<int> array, int k) {
    int n = array.size();
    int ans=0;
    vector<int> prefixSum(n+1,0);
    for(int i=1;i<=n;i++){
        prefixSum[i]=prefixSum[i-1]+array[i-1];
    }

    for(int i=0;i<=n;i++){
        if(prefixSum[i]==k){ 
            // to check single values 
            ans=max(ans,i);
            
        }
        for(int j=i+1;j<=n;j++){  // to check n size sub array , like [1,2,3] k=5 , then o/p [2,3] length 2  
            if(prefixSum[j]-prefixSum[i]==k) {
                ans = max(ans,j-i);
            }
        }
    }

    cout << "Length of longest subarray with sum " << k << " is: " << ans << endl;
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


// int main(){
//     vector<int> array={1, -2, 3, 4, -5};
//     longestSubArraySumK(array,2);
// }

/*
Optimized in n complexity using Hash Map 
{
  0  : -1,
  1  : 0,
  -1 : 1,
  2  : 2,
  6  : 3
}

*/

int WithHashMap(vector<int> array, int k) {
    int n = array.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = array[0];
    int count = 0;  // now holds longest length
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + array[i];
    }
    unordered_map<int, int> m;  // maps prefixSum → earliest index

    for (int j = 0; j < n; j++) {
        if (prefixSum[j] == k) {
            // subarray [0..j] sums to k
            count = max(count, j + 1);
        }

        int val = prefixSum[j] - k;
        if (m.find(val) != m.end()) {
            // subarray (m[val]+1 .. j) sums to k
            count = max(count, j - m[val]);
        }

        // record earliest occurrence of this prefix sum
        if (m.find(prefixSum[j]) == m.end()) {
            m[prefixSum[j]] = j;
        }
    }

    return count;
}

int main() {
    vector<int> a = {1, -2, 3, 4, -5};
    int k = 1;
    cout << "Length of longest subarray with sum " << k
         << " is: " << WithHashMap(a, k) << endl;
    return 0;
}
