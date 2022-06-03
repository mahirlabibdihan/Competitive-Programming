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
int c;
vector<int> paths[200000 + 1];
vector<int> child[200000 + 1];
void createPath(int u)
{
    // cout << u << " ";
    paths[c].push_back(u);
    if (child[u].empty())
    {
        c++;
        return;
    }
    for (int v : child[u])
    {
        createPath(v);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        paths[i].clear();
        child[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << a[i] << " ";
        if (a[i] == i)
        {
            root = i;
        }
        else
        {
            child[a[i]].push_back(i);
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << child[i] << endl;
    // cout << "---" << endl;
    c = 0;
    createPath(root);
    cout << c << endl;
    for (int i = 0; i < c; i++)
    {
        cout << paths[i].size() << endl;
        for (int j : paths[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Path is equal to the number of leaves
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
