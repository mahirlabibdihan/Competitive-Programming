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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // n=1 || m=1 -> YES
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            // cout << a[i][j] << " ";
            if (a[i][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j] == '1' && a[i + 1][j + 1] == '0')
            {
                cout << "NO" << endl;
                return;
            }
            if (a[i][j] == '1' && a[i][j + 1] == '0' && a[i + 1][j] == '1' && a[i + 1][j + 1] == '1')
            {
                cout << "NO" << endl;
                return;
            }
            if (a[i][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j] == '0' && a[i + 1][j + 1] == '1')
            {
                cout << "NO" << endl;
                return;
            }
            if (a[i][j] == '0' && a[i][j + 1] == '1' && a[i + 1][j] == '1' && a[i + 1][j + 1] == '1')
            {
                cout << "NO" << endl;
                return;
            }
        }
        // cout << endl;
    }
    cout << "YES" << endl;
}
/*
1 1
1 0

1 0
1 1

1 1
0 1

0 1
1 1
*/
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
