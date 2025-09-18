/*
Return true if subarray with 0 sum exists
Brute Force O(n^2)
Using PrefixSum + Map - O(n)
Input: array = {4,2,-3,1,6}
Output: true
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool bruteForce(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += array[j];
            if (sum == 0) {
                return true;
            }
        }
    }
    return false;
}

bool optimal(vector<int> &array) {
    int n = array.size();
    unordered_set<int> s; // prefixSum
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += array[i];
        if (prefixSum == 0 || s.find(prefixSum) != s.end()) {
            return true;
        }
        s.insert(prefixSum);
    }
    return false;
}

int main() {
    vector<int> array = {4, 2, -3, 1, 6};
    cout << "Brute Force: " << (bruteForce(array) ? "true" : "false") << endl;
    cout << "Optimal: " << (optimal(array) ? "true" : "false") << endl;
    return 0;
}
