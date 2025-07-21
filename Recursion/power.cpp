/*
2^3 =8
2*2^2 ->2*2*2^1
*/
#include <iostream>
using namespace std;

int solve(int number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return 2 * solve(number, power - 1);
}

int main()
{
    int number, power;
    cout << "Enter number" << endl;
    cin >> number;
    cout << endl
         << "Enter power" << endl;
    cin >> power;
    int ans = solve(number, power);
   cout<<endl<<number<<" to the power "<<power<<" is "<<ans;
}