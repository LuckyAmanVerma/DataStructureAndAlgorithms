/*
arr = [100, 180, 260, 310, 40, 535, 695]
Max Profit = 655

Achieved by buying at 40 and selling at 695.

| i (day) | arr\[i] | minPrice before | arr\[i] - minPrice | maxProfit after | minPrice after |
| ------- | ------- | --------------- | ------------------ | --------------- | -------------- |
| init    | 100     | 100             | -                  | 0               | 100            |
| 1       | 180     | 100             | 80                 | 80              | 100            |
| 2       | 260     | 100             | 160                | 160             | 100            |
| 3       | 310     | 100             | 210                | 210             | 100            |
| 4       | 40      | 100             | -60                | 210             | 40             |
| 5       | 535     | 40              | 495                | 495             | 40             |
| 6       | 695     | 40              | 655                | 655             | 40             |
| End     | -       | -               | -                  |           | -              |
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfitOneTransaction(vector<int> &arr) {
    int n=arr.size();
    int maxProfit =0;
    int minPrice = arr[0];

    for(int i=1;i<n;i++) {
        maxProfit =max(maxProfit,arr[i]-minPrice);
        minPrice = min(minPrice,arr[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> stockPrices = {100, 180, 260, 310, 40, 535, 695};
    int maxProfit = maxProfitOneTransaction(stockPrices);
    cout << "Maximum Profit with One Transaction: " << maxProfit << endl;
    return 0;
}

