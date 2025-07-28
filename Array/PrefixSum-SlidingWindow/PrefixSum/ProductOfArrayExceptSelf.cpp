/*
Product of Array Except Self
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> expectSelf(vector<int> array){
    int size=array.size();
    int leftProduct=1;
    int rightProduct=1;
    vector<int> ans(size);
    //left product
    for(int i=0;i<size;i++){
        ans[i]=leftProduct;
        leftProduct =leftProduct*array[i];
    }

    //right product
    for(int i=size-1;i>=0;i--){
        ans[i]=ans[i]*rightProduct;
        rightProduct =rightProduct*array[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 2, 3, 4};
    vector<int> result = expectSelf(nums);
    
    cout << "Product of array except self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}