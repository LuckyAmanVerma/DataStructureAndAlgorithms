/*
https://www.youtube.com/watch?v=Q9wXgdxJq48&t=506s
Using binary search , we can find the median in a row-wise sorted matrix.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countData(vector<vector<int>> &matrix, int mid) {
    int count = 0;
    for (const auto& row : matrix) {
        count += upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    return count;
}

int findMedian(vector<vector<int>> &matrix) {
    int r = matrix.size(), c = matrix[0].size();
    int start = INT_MAX, end = INT_MIN;
    for(int i = 0; i < r; i++) {
        start = min(start, matrix[i][0]); //smallest
        end = max(end, matrix[i][c-1]); //largest
    }
    int desired = (r * c+1 ) / 2; // position of median
    while (start < end) {
        int mid = start + (end - start)/2;
        int cnt = countData(matrix, mid);
        if (cnt < desired) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int median = findMedian(matrix);
    cout << "Median is: " << median << endl;
}