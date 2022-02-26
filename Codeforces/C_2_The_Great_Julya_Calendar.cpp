#include <iostream>
using namespace std;
typedef long long int64;
// Max substraction 9
// So only the last two digit will change
// We can store all the digits except the last two
// Initially we can store all the digits in priority queue.
// Then take the top element each time and substract it.
// Also we should replace previous last two digits with the new ones.

int solve(int n)
{
    int c = 0;
    int maxDigit = 0;
    int64 maxIdx = 0;
    int64 lastMaxIdx = 1000000000000LL;
    while (n > 0)
    {
        // cout << n << endl;
        for (int64 i = 1; (n / i) > 0 && i <= lastMaxIdx; i *= 10)
        {
            int tmp = (n / i) % 10;
            if (tmp >= maxDigit)
            {
                maxDigit = tmp;
                maxIdx = i;
            }
        }
        if (maxDigit == 9)
        {
            int64 div = (n % maxIdx) / 9;
            c += div;
            n -= div * 9;
            n -= maxDigit;
            c++;
            maxDigit = (n / maxIdx) % 10;
            if (maxDigit == 8)
            {
                lastMaxIdx = maxIdx;
            }
            else
            {
                maxDigit = 0;
                lastMaxIdx = 1000000000000LL;
            }
            // So now maxDigit decreases to 8
        }
        else
        {
            int64 div = (n % maxIdx) / maxDigit;
            n -= maxDigit;
            c++;
            if (div > 0)
            {
                lastMaxIdx = maxIdx;
            }
            else
            {
                maxDigit = 0;
                lastMaxIdx = 1000000000000LL;
            }
        }
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << endl;
}