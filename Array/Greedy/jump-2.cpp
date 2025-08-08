/*
Count no of jumps need to reach the end
Input: [3, 2, 1, 0, 4] Output: -1
Input: [2, 3, 1, 1, 4] Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int jumps2(vector<int> array) {
    int n = array.size();
    if (n <= 1) return 0;

    int jumps = 0;    // Number of jumps required
    int currEnd = 0;  // The farthest point that all previous jumps can reach
    int farthest = 0; // The farthest point that can be reached in the next jump

    for (int i = 0; i < n - 1; i++) { // We stop at n-2: when we reach n-1, we're done.
        farthest = max(farthest, i + array[i]);
        if (i == currEnd) {        // When we've gone as far as this jump lets us
            jumps++;
            currEnd = farthest;    // Move to the farthest point the next jump can reach
            if (currEnd >= n - 1) break; // If we can reach the end, break
        }
    }

    return jumps;
}

int main() {
    vector<int> array = {3, 2, 1, 0, 4};
    int result = jumps2(array);
    cout << "Minimum jumps to reach the end: " << result << endl;
    return 0;
}