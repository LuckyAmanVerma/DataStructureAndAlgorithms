/*
Merge Intervals
Given a collection of intervals, merge all overlapping intervals.
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Time Complexity: O(n log n)
*/

#include<iostream>
#include<vector>
using namespace std;

void mergeIntervalBrute(const vector<vector<int>> &array) {
    int n=array.size();
    if(n<=1) {
        cout<<"Not enough data"<<endl;
        return;
    }
    vector<vector<int>> result={};
    result.push_back(array[0]);
    int i=1;

    while(i<n) {
        int currentStart = array[i][0];
        int currentEnd = array[i][1];
        auto prev=result.back();
        int prevStart =prev[0];
        int prevEnd =prev[1];

        if(prevEnd>currentStart) {
            result[result.size()-1][1]=max(prevEnd,currentEnd);
        }
        else {
            result.push_back(array[i]);
        }
        i++;
    }
    cout<<"Merged Intervals: ";
    for(const auto& interval : result) {
        cout<<"["<<interval[0]<<", "<<interval[1]<<"] ";
    }
    cout<<endl;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    mergeIntervalBrute(intervals);
    return 0;
}