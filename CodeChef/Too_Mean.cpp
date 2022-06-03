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
// int64 DP(vector<int> a, int i)
// {
//     int x = a[i] + ;
//     return max()
// }
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    // There can be 1 to n subsequence
    // (1+2+3)/3
    // (1/4)+(2/4)+(3/2)
    double s1 = 0, s2 = 0;
    for (int i = 0; i < ceil(n / 2.0); i++)
    {
        s1 += a[i];
    }
    for (int i = ceil(n / 2.0); i < n; i++)
    {
        s2 += a[i];
    }
    s1 /= ceil(n / 2.0);
    s2 /= floor(n / 2.0);
    cout << (s1 + s2) / 2.0 << endl;
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
