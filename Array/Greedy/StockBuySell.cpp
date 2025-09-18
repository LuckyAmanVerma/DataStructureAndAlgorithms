/*
Input: arr[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy at 100, sell at 310, buy at 40 and sell at 695
*/

#include <iostream>
#include <vector>
using namespace std;

int stockBuySell(vector<int> &arr)
{
    int maxProfit = 0;
    int todayProfit = 0;
    int todayPrice = arr[0]; // initialize to first day’s price

    for (int i = 1; i < arr.size(); ++i)
    {
        todayProfit = max(0, arr[i] - todayPrice); // only positive gain
        maxProfit += todayProfit;                  // accumulate it
        todayPrice = arr[i];                       // slide window forward
    }

    return maxProfit;
}

int stockBuySellSlidingWindow(vector<int> &array)
{
    int n = array.size();
    if (n < 2)
        return 0;

    int i = 0, j = 0, k = 2;
    int maxProfit = 0;

    while (j < n)
    {
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            maxProfit += max(0, array[j] - array[i]);
            i++;
            j++;
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> stockPrices = {100, 180, 260, 310, 40, 535, 695};
    int maxProfit = stockBuySell(stockPrices);
    cout << "Maximum Profit: " << maxProfit << endl;
    cout <<"Using Sliding Window: " << stockBuySellSlidingWindow(stockPrices) << endl;
    return 0;
}