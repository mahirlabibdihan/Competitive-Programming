#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
10
5 0 5
2 1 2 0 2 1 2
1 0 1-1-1 0 1-0-1 0 1-1-1-0-1
*/
// 8 0 -> 15
// 4 0 -> 7
// 2 0 -> 3
// 10 0-> 15
// 5 1-> 7
// 2 0-> 3
/*
We are just dividing a number into 3 parts
So the total number of 1's will be equal to the initial number.
And it will be symmetric.
*/
int count;
__int64 Left, Right; // Righ-Left<10^5
void DnC(__int64 n, __int64 l, __int64 r)
{
    __int64 mid = (l + r) / 2;
    if (mid >= Left - 1 && mid < Right)
    {
        count += (n & 1);
    }
    if (n < 2)
        return;
    if (mid - 1 >= Left - 1)
        DnC(n / 2, l, mid - 1);
    if (mid + 1 <= Right - 1)
        DnC(n / 2, mid + 1, r);
}
int main()
{
    __int64 n; // 0<=n<1125899906842624
    cin >> n >> Left >> Right;
    __int64 size = (1LL << int(log2(n) + 1)) - 1;
    DnC(n, 0, size - 1);
    cout << count << endl;
}