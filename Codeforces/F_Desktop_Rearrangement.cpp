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
    // if icon index is smaller than equal total icons , then it doesn't need to be moved
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> icons(n);
    for (int i = 0; i < n; i++)
    {
        cin >> icons[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (icons[i][j] == '*')
            {
                count++;
            }
        }
    }
    // removing/adding takes O(n)
    // We can keep count of total icons = count
    //
    int k = 0;
    int tmpCount = 0;
    int result = 0;
    for (int i = 0; i < m && k < count; i++)
    {
        for (int j = 0; j < n && k < count; j++, k++)
        {
            if (icons[j][i] == '*')
            {
                tmpCount++;
            }
            if (k == count - 1)
            {
                result = count - tmpCount;
            }
        }
    }
    while (q-- > 0)
    {
        // cout << q << "->";
        int x, y;
        cin >> x >> y;
        int serial = (y - 1) * n + x;
        if (icons[x - 1][y - 1] == '*')
        {
            if (serial <= count)
            {
            }
            else
            {
                result--;
                int col = (count - 1) / (n);
                int row = count - (col * n) - 1;
                // cout << count << " " << row << " " << col << " " << n << endl;
                if (icons[row][col] == '.')
                {
                    result++;
                }
            }
            icons[x - 1][y - 1] = '.';
            count--;
        }
        else
        {
            icons[x - 1][y - 1] = '*';
            count++;
            if (serial <= count)
            {
                result--;
            }
            else
            {
                result++;
                int col = (count - 1) / (n);
                int row = count - col * n - 1;
                // cout << count << " " << row << " " << col << endl;
                if (icons[row][col] == '*')
                {
                    result--;
                }
            }
        }
        // cout << count << " " << serial << endl;
        cout << result << endl;
        // Start from last
        // Need optimization
        // I can generate next result from the previous one
        // Difference between adjacent query result is -1/0/1
    }
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
