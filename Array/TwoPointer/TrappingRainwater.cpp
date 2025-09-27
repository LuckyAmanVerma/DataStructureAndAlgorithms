/*
Trapping rainwater problem
Using two pointer approach 
1. Left Max Array 
2. Right Max Array
3. Formula - min(leftMax[i],rightMax[i])-h[i];

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getLeftMax(vector<int> &height,int n) {
    vector<int> leftMax(n);
    leftMax[0]=height[0]; // as first element k left m kuch nhi h , to vo khud hi max hoga
    for(int i=1;i<n;i++) {
        leftMax[i]=max(leftMax[i-1],height[i]);
    }
    return leftMax;
}

vector<int> getRightMax(vector<int> &height,int n) {
    vector<int> rightMax(n);
    rightMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--) {
        rightMax[i]=max(rightMax[i+1],height[i]);
    }
    return rightMax;
}

int trappingRainwater(vector<int> &height) {
    int n = height.size();
    vector<int> leftMax=getLeftMax(height,n);
    vector<int> rightMax=getRightMax(height,n);
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+= min(leftMax[i],rightMax[i])-height[i];
    }
    return sum;
}

int main() {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappingRainwater(arr);
    return 0;
}
