/*
If contain duplictes return true
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containDuplicate(vector<int> array)
{
    unordered_map<int, int> m;

    for (int x : array)
    {
        if (++m[x] > 1)
        {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> array={1,2,3,4,5};
    cout<<containDuplicate(array);
}