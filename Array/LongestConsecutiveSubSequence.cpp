/*
Approach (recap)

Sab elements ko unordered_set me daal do.

Har element ke liye check karo:

Agar num-1 set me nahi hai → iska matlab num ek new sequence ka start ho sakta hai.

Fir num+1, num+2, ... ko check karte jao jab tak present hai, length count karo.

max_len update karte raho.

Time Complexity ≈ O(n), Space ≈ O(n).
*/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int longestSubSequence(vector<int> &arr) {
    int n=arr.size();
    if(n==0) return 0;
    unordered_set<int> s(arr.begin(),arr.end());
    int maxLen=0;

    for(int num:arr) {
        if(s.find(num-1)==s.end()) {
            int curr=num;
            int len=1;
            while(s.find(curr+1)!=s.end()){
                curr=num;
                len++;
            }
            maxLen=max(maxLen,len);
        }
    }

    return maxLen;

}