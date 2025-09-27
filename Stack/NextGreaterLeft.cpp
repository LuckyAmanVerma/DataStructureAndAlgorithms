/*
Next Greater Element to Left
Input: arr[] = {4, 5, 2, 10, 8}
Output:        {-1, -1, 5, -1, 10}
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterLeft(vector<int> &array,int n) {
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    ans[0]=-1;
    s.push(array[0]);

    for(int i=1;i<n;i++) {
        int top = s.top();
        if(top>array[i]) {
            ans[i]=top;
            s.push(array[i]);
        }
        else {
            while(!s.empty() && s.top()<array[i]) {
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
                s.push(array[i]);
            }
            else{
                int top = s.top();
                if(top>array[i]) {
                    ans[i]=top;
                    s.push(array[i]);
                }
            }
        }
    }
  
    return ans;

}

int main() {
    vector<int> arr={4, 5, 2, 10, 8};
    int n=arr.size();
    vector<int> ans=nextGreaterLeft(arr,n);
    for(auto x:ans) {
        cout<<x<<" ";
    }
    return 0;
}