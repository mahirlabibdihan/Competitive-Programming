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
    // 2 2 3 4 0 1 2 0
    // 5 5 5 3 3 3 1 1
    // 0 0 0 0 1 5 5 5
    // ------------0 1
    // 2 2 3 4 4 4 4 4
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<bool> visited(n + 1);
    vector<int> postMex(n);
    int mex = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        visited[a[i]] = true;
        for (; mex <= n; mex++)
        {
            if (!visited[mex])
            {
                break;
            }
        }
        postMex[i] = mex;
    }
    // cout << postMex << endl;
    fill(visited.begin(), visited.end(), false);
    vector<int> b;
    int target = -1;
    mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (target == -1)
        {
            target = postMex[i];
        }
        visited[a[i]] = true;
        for (; mex <= n; mex++)
        {
            if (!visited[mex])
            {
                break;
            }
        }
        if (mex == target)
        {
            b.push_back(mex);
            mex = 0;
            // visited = vector<bool>(n + 1);
            fill(visited.begin(), visited.end(), false);
            target = -1;
        }
    }
    cout << b.size() << endl;
    cout << b << endl;
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
