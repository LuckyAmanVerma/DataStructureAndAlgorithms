/*
Input: arr[] = [2, 4, 1, 3, 5]   i<j && arr[i] >arr[j]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include <iostream>
#include <vector>
using namespace std;

void countInversionsBrute(vector<int> &array)
{
    int n = array.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            if (i < j && array[i] > array[j])
            {
                ans++;
            }
        }
    }
    cout << "Output " << ans << endl;
}

/*optimized solution using merge sort , 
when just have to check if low is greater than mid+1 , if yes , then increment it like mid-low+1 , 
Refer Merge Sort in SortingAlgorithms folder
*/



int main(){
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Brute Force Approach: ";
    countInversionsBrute(arr);
    return 0;
}