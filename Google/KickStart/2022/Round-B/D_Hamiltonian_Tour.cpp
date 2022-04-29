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
int V;
int N, M;
vector<string> g(200);
bool isEnd(int r, int c)
{
    return (r + c == 1);
}
string path;
int v;
bool visited[400][400];
bool hamCycleUtil(int r, int c)
{
    if (v == V)
    {
        if (isEnd(r, c))
        {
            if (r == 1)
            {
                path += 'N';
            }
            else
            {
                path += 'W';
            }
            return true;
        }
        else
            return false;
    }

    if (r > 0 && g[(r - 1) / 2][c / 2] == '*' && !visited[r - 1][c])
    {
        path += 'N';
        visited[r - 1][c] = true;
        v++;
        if (hamCycleUtil(r - 1, c))
            return true;
        path.pop_back();
        v--;
        visited[r - 1][c] = false;
    }
    if (r < N - 1 && g[(r + 1) / 2][c / 2] == '*' && !visited[r + 1][c])
    {
        path += 'S';
        visited[r + 1][c] = true;
        if (hamCycleUtil(r + 1, c))
            return true;
        path.pop_back();
        v--;
        visited[r + 1][c] = false;
    }
    if (c > 0 && g[r / 2][(c - 1) / 2] == '*' && !visited[r][c - 1])
    {
        path += 'W';
        visited[r][c - 1] = true;
        if (hamCycleUtil(r, c - 1))
            return true;
        path.pop_back();
        v--;
        visited[r][c - 1] = false;
    }
    if (c < M - 1 && g[r / 2][(c + 1) / 2] == '*' && !visited[r][c + 1])
    {
        path += 'E';
        visited[r][c + 1] = true;
        if (hamCycleUtil(r, c + 1))
            return true;
        path.pop_back();
        v--;
        visited[r][c + 1] = false;
    }
    return false;
}
string solve(vector<string> g, int n, int m)
{
    // Need to creater the graph first
    // Every node has atmost 4 adjacent node

    V = 0;
    N = 2 * n;
    M = 2 * m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '*')
            {
                V += 4;
            }
        }
    }
    v = 1;
    visited[0][0] = true;
    path.clear();
    hamCycleUtil(0, 0);
    return path;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> g[i];
        }
        cout << "Case #" << t << ": " << solve(g, n, m) << endl;
    }
    return EXIT_SUCCESS;
}
