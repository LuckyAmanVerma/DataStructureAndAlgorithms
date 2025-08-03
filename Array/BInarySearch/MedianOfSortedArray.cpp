/*
Median of two sorted array using Binary Search o(log(min(n, m)))
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
https://www.youtube.com/watch?v=F9c7LpRZWVQ

https://www.youtube.com/watch?v=6D9T2ZY8h5c
*/

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int A = nums1.size();
        int B = nums2.size();   
        if(A==0 and B==0) {
            return 0.0; // If both arrays are empty, return 0.0
        }
        if(A > B) {
            return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
        }
        int left = 0, right = A;
        int total = A + B;
        int half = (total + 1) / 2; // Half of the total length (rounded up)
        while (left <= right) {
            int i = (left + right) / 2; // Partition index for nums1
            int j = half - i; // Partition index for nums2
            int A_left_max =(i==0)?INT_MIN:nums1[i-1]; // Max of left partition of nums1
            int A_right_min =(i==A)?INT_MAX:nums1[i];
            int B_left_max =(j==0)?INT_MIN:nums2[j-1]; // Max of left partition of nums2
            int B_right_min =(j==B)?INT_MAX:nums2[j];
            if (A_left_max <= B_right_min && B_left_max <= A_right_min) {
                // Found the correct partition
                if (total % 2 == 0) {
                    return (max(A_left_max, B_left_max) + min(A_right_min, B_right_min)) / 2.0; // Even total length
                } else {
                    return max(A_left_max, B_left_max); // Odd total length
                }
            }
            else if (A_left_max > B_right_min) {
                right = i - 1; // Move towards the left in nums1
            }           
            else {
                left = i + 1; // Move towards the right in nums1
            }

        }

        return 0.0; // This line should never be reached if inputs are valid

    }
}