/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <bits/stdc++.h>
using namespace std;

/************* TEMPLATE *************/
#define FAST_IO ios::sync_with_stdio(0), cin.tie(nullptr);
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (T &i : a)
    {
        cin >> i;
    }
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (T &i : a)
    {
        cout << i << " ";
    }
    return out;
}
template <typename T>
void print(T var1)
{
#ifndef ONLINE_JUDGE
    cout << var1 << endl;
#endif
}
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
#ifndef ONLINE_JUDGE
    cout << var1 << " ";
    print(var2...);
#endif
}

typedef long long int64;
typedef unsigned long long uint64;
/**********************************************/

/************ SOLUTION *************/
void solve()
{
    // No zero
    // 0 -
    // # 2- # 1 = +- 1
    // If even number- #1=Even
    // If odd number- #1=Odd
    int n;
    cin >> n;
    if (n % 3 == 1)
    {
        for (int i = 0; n > 0; i++)
        {
            if (i % 2 == 0)
            {
                cout << 1;
                n -= 1;
            }
            else
            {
                cout << 2;
                n -= 2;
            }
        }
    }
    else
    {
        for (int i = 0; n > 0; i++)
        {
            if (i % 2 == 0)
            {
                cout << 2;
                n -= 2;
            }
            else
            {
                cout << 1;
                n -= 1;
            }
        }
    }
    cout << endl;
}
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
