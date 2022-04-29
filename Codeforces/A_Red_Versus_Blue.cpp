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
    // b<r
    int64 n, r, b;
    cin >> n >> r >> b;
    // b will be in middle
    int64 mx = ceil(1.0 * r / b);
    for (int i = 0; i < b; i++)
    {
        int k = mx;
        for (int j = mx; j >= 0; j--)
        {
            if (ceil(1.0 * (r - j) / (b - i)) <= j)
            {
                k = j;
            }
            else
            {
                break;
            }
        }
        // cout << k << " ";
        r -= k;
        for (int j = 0; j < k; j++)
        {
            cout << 'R';
        }
        cout << 'B';
    }
    for (int j = 0; j < r; j++)
    {
        cout << 'R';
    }
    cout << endl;
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

// 9 7 2
//
