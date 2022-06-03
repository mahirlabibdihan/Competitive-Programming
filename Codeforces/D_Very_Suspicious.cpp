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
vector<int64> a(38731);
void preProcess()
{

    for (int64 i = 1, j = 0, c = 0; i < 38731; i++)
    {
        c += j;
        a[i] = c;
        if (i % 3)
        {
            j += 2;
        }
    }
}
void solve()
{
    // 1 - 0
    // 2 - +2
    // 3 - +4

    // 4 - +4
    // 5 - +6
    // 6 - +8

    //
    int64 n;
    cin >> n;
    // int l = 0, r = 38730;
    int idx = lower_bound(a.begin(), a.end(), n) - a.begin();
    cout << idx << " " << a[idx] << endl;
    if (n == a[idx])
    {
        // idx-;
    }
    cout << idx << endl;
    // cout << c << endl;
}
int main()
{
    FAST_IO;
    preProcess();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
