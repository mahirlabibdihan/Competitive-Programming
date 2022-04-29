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
    int n;
    cin >> n;
    vector<int64> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int64> b(n);
    int64 result = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
        int64 moves = 0;
        for (int j = i + 1; j < n; j++)
        {
            b[j] = a[j] * (1 + (b[j - 1] / a[j]));
            moves += abs(b[j] / a[j]);
        }
        for (int j = i - 1; j >= 0; j--)
        {
            b[j] = a[j] * (-1 + (b[j + 1] / a[j]));
            moves += abs(b[j] / a[j]);
        }
        result = min(moves, result);
        // cout << b << endl;
    }
    cout << result << endl;

    // For minimum
    // One b[i] will remain zero
}
int main()
{
    FAST_IO;
    int T = 1;
    // cin >> T;
    // for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
