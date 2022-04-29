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
    // f[i] = # i is selected
    // # times is flipped = k - f[i]
    // Total # of flips = n*k - k = k(n-1)
    // Maximum flip each = k
    // Minimum flip each = 0
    // s[i] = 1 -> even # flips -> 1
    //
    int64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int64 total = k * (n - 1);
    vector<int64> f(n);
    int64 moves = k;
    for (int i = 0; i < n - 1; i++)
    {
        if (moves > 0)
        {
            int64 flips;
            if (s[i] == '1')
            {
                flips = 2 * (k / 2);
            }
            else
            {
                flips = (2 * ceil(1.0 * k / 2)) - 1;
            }
            // cout << k - flips << " " << moves << endl;
            if (k - flips <= moves)
            {
                s[i] = '1';
                f[i] = k - flips;
                moves -= f[i];
                continue;
            }
        }
        if (k % 2 == 1)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
    }
    if ((k - moves) % 2 == 1)
    {
        if (s[n - 1] == '1')
            s[n - 1] = '0';
        else
            s[n - 1] = '1';
    }
    f[n - 1] = moves;

    cout << s << endl;
    cout << f << endl;
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
