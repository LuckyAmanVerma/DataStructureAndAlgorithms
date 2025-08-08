/*
Leetcode Jump I Game
Given an array of non-negative integers, you are initially positioned at the first index. 
Each element in the array represents your maximum jump length at that position. 
Your goal is to reach the last index in the minimum number of jumps.

Input: [2,3,1,1,4]
Output: true
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include<iostream>
#include<vector>
using namespace std;

bool jumps1(vector<int> array) {
    int n = array.size();
    int jumps = 0;

    if (n == 0 || n == 1) return true;

    for (int i = 0; i < n; i++) { //{3, 2, 1, 0, 4}
        if (i > jumps) return false;  // can't reach this index
        jumps = max(jumps, i + array[i]);
        if (jumps >= n - 1) return true;  // can reach or cross end
    }

    return false;  // loop ended but couldn't reach end
}


int main() {
    vector<int> array = {3, 2, 1, 0, 4};
    if(jumps1(array)) {
        cout << "Can reach the last index." << endl;
    } else {
        cout << "Cannot reach the last index." << endl;
    }
    return 0;
}