/*
Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: 2 would be inserted before 3 at index 1.

Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: 7 would be appended at the end, index 4.

// https://leetcode.com/problems/search-insert-position/
// Time Complexity: O(log n)
*/

int SearchInsertPosition(vector<int> nums,int target) {
    int left=0;
    int n=nums.size(); //4
    int right=n-1; //3
    int result=0;
    while(left<=right){ //0<3,2<3 ,3=3
        int mid=left+(right-left)/2; // 1 ,2 ,3
        if(nums[mid]==target){   //3==7 false, 5==7 false,6==7 false
            result =mid;
            break;
        }
        if(left==right){
            if(nums[right]<target){
                result =right+1;
            }
            break;
        }
        if(right-left==1){
            if(nums[left]<target && nums[right]>target){
                result=left+1;
            }
            break;
        }
        if(nums[mid]<target){ //3<7 true,5<7 true
            left=mid+1; // left =1+1 =2 , 2+1=3
        }
        else{
            right=mid-1;
        }
    }
    return result;
}

//optimized one 

int searchInsert(vector<int> nums,int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left; 
}