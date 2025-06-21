/*
Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
ere’s what happens step by step for arr = [1, 2, 3, 4, 5]:

i = 4: arr[4] = arr[3] → arr[4] = 4 → [1, 2, 3, 4, 4]
i = 3: arr[3] = arr[2] → arr[3] = 3 → [1, 2, 3, 3, 4]
i = 2: arr[2] = arr[1] → arr[2] = 2 → [1, 2, 2, 3, 4]
i = 1: arr[1] = arr[0] → arr[1] = 1 → [1, 1, 2, 3, 4]
Finally, we set arr[0] = lastElement → arr[0] = 5 → [5, 1, 2, 3, 4]
*/


class Solution {
  public:
    void rotate(vector<int> &arr) {
        int length=arr.size();
        if(length==0){
            return arr;
        }
        int lastElement =arr[length-1]; // Store the last element
        for(int i=length-1; i>0; i--) {  //i=4 , i=3, i=2, i=1
            arr[i] = arr[i-1]; // a[4] = a[3], a[3] = a[2], a[2] = a[1], a[1] = a[0]
        }
            arr[0] = lastElement; // Place the last element at the first position

    }
};