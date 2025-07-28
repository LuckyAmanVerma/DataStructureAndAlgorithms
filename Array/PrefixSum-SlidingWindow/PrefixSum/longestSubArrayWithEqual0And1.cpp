/*
Longest Subarray with equal 0 and 1
Given an array containing only 0s and 1s, find the length of the longest
subarray with an equal number of 0s and 1s.
Example:
Input: [0, 1, 0, 1, 0, 1]
Prefix Sum: [-1, 0, -1, 0, -1, 0]
Output: 6
Explanation: The entire array has an equal number of 0s and 1s, so the length is 6.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int withEqualZeroAndOne(vector<int>& array) {
int size = array.size();
    unordered_map<int, int> prefixSumMap;
    int maxLength = 0;
    int sum = 0;

    // Initialize the map with the base case
    prefixSumMap[0] = -1; // This handles the case where the entire array is valid

    for (int i = 0; i < size; i++) {
        // Convert 0 to -1 for easier calculation
        sum += (array[i] == 0) ? -1 : 1;

        // Check if this sum has been seen before
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            // Calculate the length of the subarray
            maxLength = max(maxLength, i - prefixSumMap[sum]);
        } else {
            // Store the first occurrence of this sum
            prefixSumMap[sum] = i;
        }
    }

    return maxLength;

}

int main(){
    vector<int> array={0,1,0,1,0,1};
    cout<<withEqualZeroAndOne(array)
}
