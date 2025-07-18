/*
logn , works on sorted array 
[1,2,3,4,5,6,7] target =2;
*/
#include<iostream>
#include<vector>

int binarySearch(std::vector<int> array,int target){
    int n=array.size();
    int start=0;
    int end=n-1;
    int result=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            result=array[mid];
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
using namespace std;
int main(){
    vector<int> data={};
    return 0;
}