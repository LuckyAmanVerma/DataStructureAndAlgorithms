/*
Container Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] == nums[j] 
and abs(i - j) <= k.
Input: nums = [1,2,3,1], k = 3
Output: true
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containDuplicate2(vector<int> array,int k) {
    int size = array.size();
    unordered_map<int,int> m;

    for(int i=0;i<size;i++) {
        if(m.find(array[i])!=m.end()) {
            if(i-m[array[i]]<=k){
                return true;
            }
        }
        m[array[i]]=i;
    }
    return false;
}

int main(){
    vector<int> array={1,2,3,4};
    cout<<containDuplicate2(array,3);
}

