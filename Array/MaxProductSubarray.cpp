/*
Input  : array = {2,3,-2,4}
Output : 6
*/

#include<iostream>
#include<vector>
using namespace std;

int maxProductSubarray(vector<int> &arr) {
    int n = arr.size();
    if(n==0) return 0;
    int maxProduct =arr[0];
    int maxVal =arr[0];
    int minVal=arr[0];

    for(int i=1;i<n;i++) {
        if(arr[i]<0) {
            swap(maxVal,minVal);
        }

        maxVal = max(arr[i],arr[i]*maxVal);
        minVal = min(arr[i],arr[i]*minVal);

        maxProduct = max(maxProduct,maxVal);
    }

    return maxProduct;

}

int main() {
    vector<int> array = {2, 3, -2, 4};
    cout << "Max Product Subarray: " << maxProductSubarray(array) << endl;
    return 0;
}