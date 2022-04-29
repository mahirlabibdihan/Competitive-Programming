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

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> p(m);
    for (int i = 0, j = 0; i < m; i++)
    {
        for (; j < n; j++)
        {
            if (s[j] == t[i])
            {
                p[i].first = j++;
                break;
            }
        }
    }
    for (int i = m - 1, j = n - 1; i >= 0; i--)
    {
        for (; j >= 0; j--)
        {
            if (s[j] == t[i])
            {
                p[i].second = j--;
                break;
            }
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    int maxWidth = 0;
    for (int i = 1; i < m; i++)
    {
        maxWidth = max(maxWidth, p[i].second - p[i - 1].first);
    }
    cout << maxWidth << endl;
}
int main()
{
    FAST_IO;
    int T;
    // cin >> T;
    // for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
