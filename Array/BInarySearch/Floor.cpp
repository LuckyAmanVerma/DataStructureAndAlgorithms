/*
Find floor of an element in a sorted array.
The floor of an element is the largest element in the array that is less than or equal to the given element.
Input: [1, 2, 8, 10, 10, 12, 19], target = 5
Output: 2
*/
#include <iostream>
#include <vector>
using namespace std;

int findFloor(const vector<int>& array, int target) {
    int start = 0;
    int end = array.size() - 1;
    int floor = -1; // Initialize floor to -1 (not found)

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (array[mid] == target) {
            return array[mid]; // Found exact match
        } else if (array[mid] < target) {
            floor = array[mid]; // Update floor
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    
    return floor; // Return the largest element less than or equal to target
}

int main() {
    vector<int> data = {1, 2, 8, 10, 10, 12, 19};
    int target = 5;
    int result = findFloor(data, target);
    
    if (result != -1) {
        cout << "Floor of " << target << " is: " << result << endl;
    } else {
        cout << "No floor found for " << target << endl;
    }
    
    return 0;
}