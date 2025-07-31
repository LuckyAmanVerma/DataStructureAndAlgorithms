/*
First and last occurence of an element in a sorted array
This code finds the first and last occurrence of a given element in a sorted array using binary search
Input: [1, 2, 2, 2, 3, 4, 5], target = 2

*/

#include<iostream>
#include<vector>
using namespace std;

void firstAndLast(vector<int> array,int k) {
    int size=array.size();
    int start=0;
    int end=size-1;
    int first=-1;
    int last=-1;
    for(int i=0;i<size;i++) {
        int mid=start+(end-start)/2;
        if(array[mid]==k){
           first=mid;
           end=mid-1; // continue searching in the left half for the first occurrence
        }
        else if(array[mid]<k) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    start=0; // Reset start for the second search
    end=size-1; // Reset end for the second search

    for(int i=0;i<size;i++) {
        int mid=start+(end-start)/2;
        if(array[mid]==k){
           last=mid;
           start=mid+1; // continue searching in the right half for the last occurrence   
        }
        else if(array[mid]<k) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    cout<<first<<endl<<last<<endl;
}

int main() {
    vector<int> data = {2, 2, 2, 2, 3, 4, 5};
    int target = 2;
    firstAndLast(data, target);
    return 0;
}

