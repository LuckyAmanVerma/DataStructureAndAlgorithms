/*
Next Smaller Left 
Input: arr[] = {4, 5, 2, 10, 11}
Output:        {-1, 4, -1, 2, 10}
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerLeft(vector<int> &array,int n) {
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    ans[0]=-1;
    s.push(array[0]);

    for(int i=1;i<n;i++) {
        int top =s.top();
        if(top<array[i]){
            ans[i]=top;
            s.push(array[i]);
        }
        else {
            while(!s.empty() && s.top()>array[i]) {
                s.pop();
            }
            if(s.empty()) {
                ans[i]=-1;
                s.push(array[i]);
            }
            else if(s.top()<array[i]) {
                ans[i]=s.top();
                s.push(array[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr={4, 5, 2, 10, 11};
    int n=arr.size();
    vector<int> ans=nextSmallerLeft(arr,n);
    for(auto x:ans) {
        cout<<x<<" ";
    }
    return 0;
}