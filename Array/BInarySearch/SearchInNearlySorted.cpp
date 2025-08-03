/*
Input: [1,2,4,3,5], target = 3
Output: Element found at index: 3
*/

#include <iostream>
#include <vector>
using namespace std;

int nearlySortedSearch(const vector<int>& array, int target) {
    int size = array.size();
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if the middle element is the target
        if (array[mid] == target) {
            return mid;
        }

        // Check if the previous element is the target
        if (mid > start && array[mid - 1] == target) {
            return mid - 1;
        }

        // Check if the next element is the target
        if (mid < end && array[mid + 1] == target) {
            return mid + 1;
        }

        // Adjust search range based on the value of the middle element
        if (array[mid] < target) {
            start = mid + 2; // Skip one element to handle nearly sorted condition
        } else {
            end = mid - 2; // Skip one element to handle nearly sorted condition
        }
    }
    return -1; // Target not found
}

int main() {
    vector<int> data = {1, 2, 4, 3, 5};
    int target = 3;
    int result = nearlySortedSearch(data, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}