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
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
        sort(b[i].begin(), b[i].end());
    }
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                c[i]++;
            }
        }
        if (c[i] > 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<pair<int, int>> d(n, {-1, -1});
    pair<int, int> tmp = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 2)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != b[i][j])
                {
                    if (d[i].first == -1)
                    {
                        d[i].first = j;
                        tmp.first = j;
                    }
                    else
                    {
                        d[i].second = j;
                        tmp.second = j;
                    }
                }
            }
        }
    }
    if (tmp.first == -1)
    {
        tmp.first = 0;
        tmp.second = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i].first == -1)
        {
            if (a[i][tmp.first] != a[i][tmp.second])
            {
                cout << -1 << endl;
                return;
            }
        }
        else
        {
            if (d[i] != tmp)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
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
