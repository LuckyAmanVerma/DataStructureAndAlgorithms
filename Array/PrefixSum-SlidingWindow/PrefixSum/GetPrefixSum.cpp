
/*
Prefix Sum
Input: [1,2,3,4,5]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrefixSum(vector<int> array)
{
    int size = array.size();
    vector<int> ans(size + 1);
    ans[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        ans[i] = array[i - 1] + ans[i - 1];
    }
    return ans;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    vector<int> ans = getPrefixSum(array);
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
