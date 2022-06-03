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
    // n is power of two
    // 0 to n-1
    // Two option
    // Exists
    // Not exists
    int n, k;
    cin >> n >> k;
    if (k == n - 1)
    {
        if (n == 4)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (i == 0)
                {
                    cout << 0 << " " << 2 << endl;
                }
                else if (i == 1)
                {
                    cout << 1 << " " << n - 3 << endl;
                }
                else if (i != 2)
                {
                    cout << i << " " << n - 1 - i << endl;
                }
            }
            cout << n - 2 << " " << n - 1 << endl;
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (i == 0)
            {
                cout << i << " " << n - 1 - k << endl;
            }
            else if (i == k || i == n - 1 - k)
            {
                cout << k << " " << n - 1 << endl;
            }
            else
            {
                cout << i << " " << n - 1 - i << endl;
            }
        }
    }
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
