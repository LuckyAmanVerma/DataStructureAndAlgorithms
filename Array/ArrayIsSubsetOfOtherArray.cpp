/*
a[] = [10, 5, 2, 23, 19]
Sorted → [2, 5, 10, 19, 23]

b[] = [19, 5, 3]
Sorted → [3, 5, 19]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubset(vector<int> &a,vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int m=a.size();
    int n=b.size();
    int i=0;
    int j=0;

    while(i<m && j<n) {
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]==b[j]) {
            i++; j++;
        }
        else {
            return false;
        }
    }
    return (j==n);
}

int main() {
    vector<int> a = {10, 5, 2, 3, 23, 19};
    vector<int> b = {19, 5, 3};

    if(isSubset(a,b)) {
        cout << "b[] is a subset of a[]" << endl;
    }
    else {
        cout << "b[] is NOT a subset of a[]" << endl;
    }
    return 0;
}