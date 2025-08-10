/*
Two Sum pairs equal to 0
Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]

Time Complexity: O(n log n) for sorting + O(n) for the two-pointer search = O(n log n)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> twoSumEqualZero(vector<int>& array,int target) {
    sort(array.begin(), array.end()); //[-4, -1, -1, 0, 1, 2]
    int n=array.size();
    int start=0;
    int end=n-1;
    int sum =0;
    vector<pair<int, int>> result;
    while(start < end) { //[-4, -1, -1, 0, 1, 2]
        sum = array[start] + array[end];
        if(sum == target) {
            result.push_back({array[start], array[end]});

            // Skip duplicates for start
            int x = array[start];
            while(start < end && array[start] == x) {
                start++;
            }
            
            // Skip duplicates for end
            int y = array[end];
            while(start < end && array[end] == y) {
                end--;
            }
        }
        else if(sum < target) {
            start++;
        }
        else {
            end--;
        }
    }
    return result;
    }

int main() {
    vector<int> arr = {-1, 0, 0, 2, 1, -2};
    int target = 0;
    vector<pair<int, int>> result = twoSumEqualZero(arr, target);
    for (const auto &pair : result) {
        cout << "[" << pair.first << ", " << pair.second << "] ";
    }
    return 0;
}