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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first and a.second > b.second)
        return true;
    else
        return false;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> j(n, false);
    vector<pair<int, int>> b(n);
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        b[i].first = (n - i - 1) - a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        j[b[i].second] = true;
    }
    int c = 0;
    int64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (j[i])
        {
            c++;
        }
        else
        {
            sum += a[i] + c;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << j[i] << " ";
    // }
    // cout << endl;
    cout << sum << endl;
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
