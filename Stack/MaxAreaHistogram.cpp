/*
Max Area in Histogram
Input: arr[] = {6, 2, 5, 4, 5, 1, 6}
Output: 12

Using NSL , NSR , and width = NSR-NSL-1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerLeft(vector<int> &array) {
    int n = array.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && array[s.top()] >= array[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmallerRight(vector<int> &array) {
    int n = array.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(n);
    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != n && array[s.top()] >= array[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int maxAreaHistogram(vector<int> &array) {
    int n = array.size();
    vector<int> left = nextSmallerLeft(array);
    vector<int> right = nextSmallerRight(array);
    vector<int> width(n);
    for (int i = 0; i < n; i++) {
        if (left[i] == -1) left[i] = -1;
        if (right[i] == n) right[i] = n;
        width[i] = right[i] - left[i] - 1;
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int area = array[i] * width[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> arr={6, 2, 5, 4, 5, 1, 6};
    int ans=maxAreaHistogram(arr);
    cout<<ans;
    return 0;
}