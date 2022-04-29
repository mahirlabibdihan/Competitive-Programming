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
vector<int> dp(11, 0);
void solve()
{
    // 0-100
    // 90*1 + 9*2 + 1*3
    // 43 - 57
    int l, r;
    cin >> l >> r;
    int lC = 0, rC = 0;
    // cout << dp << endl;
    // l--;
    for (int i = 1000000000, j = 10; i > 0; i /= 10, j--)
    {
        lC += (l / i) * dp[j];
        rC += (r / i) * dp[j];
        // cout << i << " " << j << endl;
        l %= i;
        r %= i;
    }
    // cout << rC << " " << lC << endl;
    cout << rC - lC << endl;
}
int main()
{
    FAST_IO;
    int T;
    for (int i = 1; i <= 10; i++)
    {
        dp[i] = dp[i - 1] * 10 + 1;
    }
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
