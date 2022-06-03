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
    // First find the missing game paritcipants
    // Then find who has lower p
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < (n * (n - 1) / 2) - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        grid[y][x] = -1;
    }
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && !grid[i][j])
            {
                a = i;
                b = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i != a) && (grid[a][i] != grid[b][i]))
        {
            if (grid[a][i] > grid[b][i])
            {
                cout << a << " " << b << endl;
            }
            else
            {
                cout << b << " " << a << endl;
            }
            return;
        }
    }
    cout << a << " " << b << endl;
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
