/*
 Full Flow of “Next Permutation” — Hinglish Mein
- Right se scan karo
Pehla aisa index i-1 dhoondo jahan arr[i-1] < arr[i] — ye hota hai pivot point
- Agar aisa point nahi milta, to array descending hai → reverse karke smallest permutation milega
- Successor dhoondo
Pivot ke baad ke elements mein (right se) pehla aisa element arr[j] dhoondo jo pivot se bada ho: arr[j] > arr[i-1]
- Swap karo
Ab arr[i-1] aur arr[j] ko swap kar do — ye next bada step banata hai
- Reverse karo suffix ko
Index i se array ke end tak wale elements ko reverse karo — taaki woh minimal ho jaye

Input:[1,2,3]
Output:[1,3,2]

Input:[3,2,1]
Output:[1,2,3]

Input:[1,1,5]
Output:[1,5,1]

*/

#include <iostream>
#include <vector>
using namespace std;

// 1) Find the largest index `pivot` such that arr[pivot] < arr[pivot+1].
//    Return -1 if the entire array is non-increasing.
int findPivot(const vector<int>& arr) {
    for (int i = (int)arr.size() - 2; i >= 0; --i) {
        if (arr[i] < arr[i + 1]) {
            return i;
        }
    }
    return -1;
}

// 2) Find the smallest index > pivot from the right whose value > arr[pivot].
int findSuccessor(const vector<int>& arr, int pivot) {
    for (int j = (int)arr.size() - 1; j > pivot; --j) {
        if (arr[j] > arr[pivot]) {
            return j;
        }
    }
    return -1;  // will not happen if pivot != -1
}

// 3) Swap arr[i] and arr[j] without std::swap
void doSwap(vector<int>& arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 4) Reverse elements in arr from index `start` to the end
void reverseSuffix(vector<int>& arr, int start) {
    int i = start, j = (int)arr.size() - 1;
    while (i < j) {
        int tmp = arr[i];
        arr[i++] = arr[j];
        arr[j--] = tmp;
    }
}

// Main driver: computes next permutation in place
void nextPermutation(vector<int>& arr) {
    int pivot = findPivot(arr);

    // If no pivot, array is highest permutation → reverse to smallest
    if (pivot == -1) {
        reverseSuffix(arr, 0);
        return;
    }

    int successor = findSuccessor(arr, pivot);
    doSwap(arr, pivot, successor);
    reverseSuffix(arr, pivot + 1);
}

// Utility to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 4, 3, 2};
    cout << "Original: ";
    printArray(arr);

    nextPermutation(arr);
    cout << "Next Perm: ";
    printArray(arr);

    nextPermutation(arr);
    cout << "Next Perm: ";
    printArray(arr);

    return 0;
}