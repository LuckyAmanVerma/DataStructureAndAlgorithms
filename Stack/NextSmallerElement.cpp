/*
Next Smaller Element
Given an array, find the next smaller element for each element of the array. The next smaller
Input: arr[] = {4, 5, 2, 10, 11}
Output:        {2, 2, -1, -1, -1}
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmaller(vector<int> &array) {
    int n=array.size();
    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    for(int i=n-1;i>=0;i--) {
        int top=s.top();
        if(top<array[i]) {
            ans[i]=top;
            s.push(array[i]);
        }
        else {
            while(s.top()>array[i]) {
                s.pop();
            }
            int top = s.top();
            ans[i]=top;
            s.push(array[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr={4, 5, 2, 10,11};
    vector<int> ans=nextSmaller(arr);
    for(auto x:ans) {
        cout<<x<<" ";
    }
    return 0;
}