/*
Using two ponter approach to find the maximum area of water that can be contained between two lines.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49  
Time Complexity: O(n)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int left = 0;
        int right = length-1;
        int ans=0;
        while(left<right) {
            int w =right-left;
            int h =min(height[right],height[left]);
             ans = max(ans,w*h);
            if(height[left]<height[right]) {
                left++;
            }
            else {
                right --;
            } 
        }
        return ans;
    }
};