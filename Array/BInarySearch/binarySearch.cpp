/*
logn , works on sorted array 
[1,2,3,4,5,6,7] target =2;
*/
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> array,int target){
    int n=array.size();
    int start=0;
    int end=n-1;
    int result=-1;
    while(start<=end){  // for binary sorted array also , same logic work , in that case we will not have to check for the end condition
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            cout<<"start "<<start<<endl<<"end "<<end<<endl;
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
    cout<<"start "<<start<<endl<<"end "<<end<<endl;
    return result;
}
int main(){
    vector<int> data={1,2,3,4,6,7};
    int ans = binarySearch(data, 6);
    if(ans!=-1){
        cout << "Element found: " << ans << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}