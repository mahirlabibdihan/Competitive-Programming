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
int64 n, a, b;
vector<int64> x(200001);
void solve()
{
    // 5 6 3
    // 1 5 6 21 30
    // (3^5)*(1+5+6+21+30)
    // After every step I have two option
    // Either go to latest conquered kingdom
    // Or conquer next kingdom
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    int64 cIdx = 0;
    int64 cost = 0;
    for (int i = 1; i <= n; i++)
    {
        cost += b * (x[i] - x[cIdx]);
        if (a * (x[i] - x[cIdx]) < (n - i) * b * (x[i] - x[cIdx]))
        {
            cost += a * (x[i] - x[cIdx]);
            cIdx = i;
        }
    }
    cout << cost << endl;
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
