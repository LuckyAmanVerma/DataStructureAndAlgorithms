/*
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/

#include<iostream>
#include<vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
        int size=nums.size();
        vector<int> sumLeft(size);
        vector<int> sumRight(size);
        int leftProduct=0;
        int rightProduct=0;
        int ans=-1;
        for(int i=0;i<size;i++) {
            sumLeft[i]=leftProduct;
            leftProduct=leftProduct+nums[i];
        }

        for(int i=size-1;i>=0;i--) {
            sumRight[i]=rightProduct;
            rightProduct=rightProduct+nums[i];
        }

        for(int i=0;i<sumLeft.size();i++) {
            if(sumLeft[i]==sumRight[i]) {
                ans=i;
                break;
            }
        }
        return ans;
    }

int main(){
    vector<int> nums={1,7,3,6,5,6};
    cout<<"Pivot index is "<<pivotIndex(nums);
}