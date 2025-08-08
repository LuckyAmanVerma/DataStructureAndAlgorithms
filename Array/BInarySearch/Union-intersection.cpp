/*
Union of two sorted arrays without using extra space
Approach:
1. Initialize pointers for both arrays.
2. Compare elements at both pointers.
3. Print the smaller element and move the corresponding pointer.
4. If elements are equal, print one and move both pointers.
5. Continue until all elements are processed.
Input:[1, 2, 3, 4, 5] ,[2, 3, 5, 6, 7]
Output: 1 2 3 4 5 6 7
Time Complexity: O(n + m) where n and m are the sizes of the two arrays.

Intersection of two sorted arrays without using extra space
Approach:
1. Initialize pointers for both arrays.
2. Compare elements at both pointers.
3. If elements are equal, print one and move both pointers.
4. If the element in the first array is smaller, move the pointer in the first array.
5. If the element in the second array is smaller, move the pointer in the second array.
6. Continue until all elements are processed.
Input:[1, 2, 3, 4, 5] ,[2, 3, 5, 6, 7]
Output: 2 3 5
Time Complexity: O(n + m) where n and m are the sizes of the two arrays.
*/

#include<iostream>
#include<vector>
using namespace std                                                                      ;

void Union(vector<int> nums1,vector<int> nums2)                                          {
    int size1=nums1.size()                                                               ;
    int size2=nums2.size()                                                               ;
    if(!size1 && !size2)                                                                 {
        cout<<"Nothing to show"<<endl                                                    ;
       return                                                                            ;}
    if(!size1 ||!size2)                                                                  {
        cout<<"One of the array is empty"                                                ;
       return                                                                            ;}
    int i=0                                                                              ;
    int j=0                                                                              ;
    while(i<size1 && j<size2)                                                            {
        if(nums1[i]<nums2[j])                                                            {
            cout<<" "<<nums1[i]<<" "                                                     ;
            i++                                                                          ;}
        else if(nums1[i]>nums2[j])                                                       {
            cout<<" "<<nums2[j]<<" "                                                     ;
            j++                                                                          ;}
        else                                                                             {
            cout<<" "<<nums1[i]<<" "                                                     ;
            i++                                                                          ;
            j++                                                                          ;}}}

void intersection(vector<int> nums1, vector<int> nums2)                                  {
    int size1 = nums1.size()                                                             ;
    int size2 = nums2.size()                                                             ;
    if (!size1 && !size2)                                                                {
        cout << "Nothing to show" << endl                                                ;
        return                                                                           ;}
    if (!size1 || !size2)                                                                {
        cout << "One of the array is empty"                                              ;
        return                                                                           ;}
    int i = 0                                                                            ;
    int j = 0                                                                            ;
    while (i < size1 && j < size2)                                                       {
        if (nums1[i] < nums2[j])                                                         {
            i++                                                                          ;
        } else if (nums1[i] > nums2[j])                                                  {
            j++                                                                          ;
        } else                                                                           {
            cout << " " << nums1[i] << " "                                               ;
            i++                                                                          ;
            j++                                                                          ;}}}

int main()                                                                               {
    vector<int> nums1 = {1, 2, 3, 4, 5                                                  };
    vector<int> nums2 = {2, 3, 5, 6, 7                                                  };
    Union(nums1, nums2)                                                                  ;
    cout << endl                                                                         ;
    intersection(nums1, nums2)                                                           ;
    cout << endl                                                                         ;
    return 0                                                                             ;}