
/*
We solve it , by divide the problem into 2 sum problem 
n1+n2+n3=0
n1+n2=-n3
Input: arr = [-1, 0, 1, 2, -1, -4]  sum =0 
Output: [[-1, -1, 2], [-1, 0, 1]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> twoSum(const vector<int>& array, int start, int target) {
    int n = array.size();
    int left = start, right = n - 1;
    vector<pair<int, int>> result;
    while (left < right) {
        int sum = array[left] + array[right];

        if (sum == target) {
            result.push_back({array[left], array[right]});

            int x = array[left];
            while (left < right && array[left] == x) left++;

            int y = array[right];
            while (left < right && array[right] == y) right--;
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }
    return result;
}

vector<tuple<int,int,int>> threeSum(vector<int> &array,int target) {
    // Sort the array for two-pointer approach
    sort(array.begin(), array.end());
    int n = array.size();
    vector<tuple<int,int,int>> result;
    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates for the first element
        if (i > 0 && array[i] == array[i-1]) continue;
        int newTarget = target - array[i];
        // Use twoSum on the subarray after i
        vector<pair<int, int>> pairs = twoSum(array, i+1, newTarget);
        for (auto &p : pairs) {
            result.push_back({array[i], p.first, p.second});
        }
    }
    return result;

}

int main() {
    vector<int> array={-1, 0, 1, 2, -1, -4};
    int target =2;
    vector<tuple<int,int,int>> result = threeSum(array,target);
    for (const auto &triplet : result) {
        cout << "[" << get<0>(triplet) << ", " << get<1>(triplet) << ", " << get<2>(triplet) << "] ";
    }
    return 0;

}