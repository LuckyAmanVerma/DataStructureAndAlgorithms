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

int binarySearch(vector<int> array,int target){
    int n=array.size();
    int start=0;
    int end=n-1;
    int result=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            result=array[mid];
            cout << "Element found at index: " << mid << endl;
            break;
        }
        if(array[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return result;
}

int findElement(vector<int> array,int target) {
    int smallest = countRotations(array);
    int n = array.size();
    if (smallest == 0) {
        return binarySearch(array, target);
    }
    if (target >= array[0]) {
        return binarySearch(vector<int>(array.begin(), array.begin() + smallest), target);
    } else {
        return binarySearch(vector<int>(array.begin() + smallest, array.end()), target);
    }

}

int main() {
    vector<int> data = { 4, 5, 1,2,3};
    // int rotations = countRotations(data);
    // cout << "The array is rotated " << rotations << " times." << endl;
    int target = 4;
    int result = findElement(data, target);
    if (result != -1) {
        cout << "Element found: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}