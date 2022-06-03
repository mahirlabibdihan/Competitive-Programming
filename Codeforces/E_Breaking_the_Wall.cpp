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
int64 minShots(int l, int r)
{
    return ceil(l / 2.0) + ceil(r / 2.0);
}
int64 minShots2(int l, int r)
{
    return ceil((l + r) / 2.0);
}
int64 minShotsAdj(int l, int r)
{
    int mn = min(l, r);
    int mx = max(l, r);
    if (2 * mn < mx)
    {
        return ceil(mx / 2.0);
    }
    else
    {
        return ceil((mn + mx) / 3.0);
    }
}
void solve()
{
    // Its better to go for adjacent I guess
    int64 n;
    cin >> n;
    vector<int64> a(n);
    cin >> a;
    int mn = 0, lastMn = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[mn])
        {
            lastMn = mn;
            mn = i;
        }
        else if (lastMn == -1 || a[i] < a[lastMn])
        {
            lastMn = i;
        }
    }
    int64 mnShots;
    if (abs(mn - lastMn) == 1)
    {
        mnShots = minShotsAdj(a[mn], a[lastMn]);
    }
    else if (abs(mn - lastMn) == 2)
    {
        mnShots = min(minShots(a[mn], a[lastMn]), minShots2(a[mn], a[lastMn]));
    }
    else
    {
        mnShots = minShots(a[mn], a[lastMn]);
    }
    for (int i = 1; i < n; i++)
    {
        mnShots = min(mnShots, minShotsAdj(a[i], a[i - 1]));
    }
    for (int i = 1; i < n - 1; i++)
    {
        mnShots = min(mnShots, minShots2(a[i - 1], a[i + 1]));
    }
    cout << mnShots << endl;
}
int main()
{
    FAST_IO;
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
