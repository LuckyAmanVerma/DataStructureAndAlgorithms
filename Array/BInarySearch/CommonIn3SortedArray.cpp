/*
Common elements in 3 sorted arrays
Input: arr1 = [1, 2, 3, 4, 5], arr2 = [2, 3, 5, 7], arr3 = [1, 2, 3, 4, 5, 6, 7]
Output: [2, 3]
*/

#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

vector<int> findCommonElements(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
    vector<int> result;
    if (A.empty() || B.empty() || C.empty()) return result;

    if(A.size()>B.size()||A.size()>C.size()){

        if(B.size()>C.size()){
            return findCommonElements(C,B,A);
        }
        else {
            return findCommonElements(B,C,A);
        }
    }

    for (int i = 0; i < A.size(); ++i) {
        // // Skip duplicates in A
        if (i > 0 && A[i] == A[i - 1]) continue;

        if (binarySearch(B, A[i]) && binarySearch(C, A[i])) {
            result.push_back(A[i]);
        }
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 5, 7};
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};

    vector<int> commonElements = findCommonElements(arr1, arr2, arr3);
    for (int num : commonElements) {
        cout << num << " ";
    }
    return 0;
}