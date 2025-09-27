/*
Next Larger Element using stack .
Input: arr[] = {4, 5, 2, 10, 8}
Output:        {5, 10, 10, -1, -1}
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextLarger(vector<int> &array,int n) {
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    s.push(array[n-1]);
    ans[n-1]=-1;

    for(int i=n-2;i>=0;i--) {
        int top =s.top();
        if(top>array[i]) {
            ans[i]=top;
            s.push(array[i]);
        }
        else {
            while(s.top()<array[i]){
                s.pop();
                if(s.empty()){
                    s.push(-1);
                    break;
                }
            }
            int top = s.top();
            ans[i]=top;
            s.push(array[i]);
        }
    }
    return ans;

}

int main() {
    vector<int> arr={4, 5, 2, 10, 8};
    int n=arr.size();
    vector<int> ans=nextLarger(arr,n);
    for(auto x:ans) {
        cout<<x<<" ";
    }
    return 0;
}