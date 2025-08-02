/*
Input: [3, 4, 5, 1, 2], Output: 3
[1,2,3,4,5] -> [5,1,2,3,4]->[4,5,1,2,3]
This code finds the number of times a sorted array has been rotated using binary search.
We have to return the index of the smallest element in the rotated array.
*/

#include <iostream>
#include <vector>
using namespace std;

int countRotations(const vector<int>& array) {
    int size = array.size();
    int start=0;
    int end=size-1;
    int count=0;

    for(int i=0;i<size;i++) { 
        int mid = start+(end-start)/2; 
        int prev =(mid-1+size)%size;
        int next=(mid+1)%size;
        if(array[mid]<=array[next] && array[mid]<=array[prev]) {
            count=mid;
        }
        else if(array[start]<=array[mid]){
            start=mid+1;
        }
        else if(array[end]>=array[mid]){
            end=mid-1;
        }
    }
    return count;
}

int main() {
    vector<int> data = { 4, 5, 1,2,3};
    int rotations = countRotations(data);
    cout << "The array is rotated " << rotations << " times." << endl;
    return 0;
}