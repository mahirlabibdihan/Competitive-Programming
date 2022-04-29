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
    int64 n;
    cin >> n;
    vector<int64> a(n);
    cin >> a;
    map<int64, int> count;
    int mxCount = 0;
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
        mxCount = max(mxCount, count[a[i]]);
    }

    // mxCount -> n
    int nCopies = 0;
    int nSwaps = 0;
    for (int64 i = mxCount;; i *= 2)
    {
        if (i < n)
        {
            nCopies++;
        }
        else
        {
            break;
        }
    }
    cout << nCopies + n - mxCount << endl;

    // 1 2 3 4 5 6
    // 2 5 7 6 3 | 2 5 7 6 3 -> C
    // 2 2 7 6 3 | 5 5 7 6 3 -> S
    // 2 2 7 6 3 | 2 2 7 6 3 -> C
    // 2 2 2 6 3 | 7 2 7 6 3 -> S
    // 2 2 2 2 3 | 7 6 7 6 3 -> S
    // 2 2 2 2 3 | 2 2 2 2 3 -> C

    // 0 1 3 3 7 0 | 0 1 3 3 7 0
    // 0 0 3 3 7 0 | 1 1 3 3 7 0
    // 0 0 0 3 7 0 | 1 1 3 3 7 3
    // 0 0 0 3 7 0 | 0 0 0 3 7 0 | 1 1 3 3 7 3
    // 0 0 0 0 7 0 | 0 0 3 3 7 0
    // 0 0 0 0 0 0 | 0 7 3 3 7 0
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
