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
struct Move
{
    int lX, lY, rX, rY;
};
void solve()
{
    // Bruteforce
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
    vector<Move> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j > 0; j--)
        {
            if (a[i][j] == '1')
            {
                result.push_back({i + 1, j, i + 1, j + 1});
            }
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i][0] == '1')
        {
            result.push_back({i, 1, i + 1, 1});
        }
    }
    if (a[0][0] == '1')
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result.size() << endl;
        for (auto i : result)
        {
            cout << i.lX << " " << i.lY << " " << i.rX << " " << i.rY << endl;
        }
    }
}
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
