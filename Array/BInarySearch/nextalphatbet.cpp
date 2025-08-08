/*
Next alphabet in sorted array
The next alphabet is the smallest element in the array that is greater than the given element.
Input: ['a', 'b', 'c', 'd', 'e'], target = 'c'
Output: 'd'
*/
#include <iostream>
#include <vector>
using namespace std;
char nextAlphabet(const vector<char>& array, char target) {
    int start = 0;
    int end = array.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (array[mid] <= target) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }

    // If start is within bounds, return the next alphabet
    if (start < array.size()) {
        return array[start];
    } else {
        return '\0'; // Return null character if no next alphabet found
    }
}