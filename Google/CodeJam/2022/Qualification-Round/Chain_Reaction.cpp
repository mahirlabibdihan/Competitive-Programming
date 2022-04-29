/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <iostream>
#include <vector>
#include <climits>
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
vector<int64> minBranch(100001);
vector<int64> maxBranch(100001);
vector<int64> maxBranchIdx(100001);
vector<int64> minBranchIdx(100001);
vector<int64> F(100001), P(100001);
vector<int64> adj[100001];
int64 ans;
void dfs(int64 u, int64 m)
{
    if (adj[u].empty())
    {
        ans += max(F[u], m);
    }
    else
    {
        dfs(minBranchIdx[u], max(m, F[u]));
        for (int64 v : adj[u])
        {
            if (v != minBranchIdx[u])
            {
                dfs(v, 0);
            }
        }
    }
}
int64 dfsMax(int64 u)
{
    maxBranch[u] = 0;
    maxBranchIdx[u] = (adj[u].empty() ? -1 : adj[u][0]);
    minBranch[u] = INT_MAX;
    minBranchIdx[u] = (adj[u].empty() ? -1 : adj[u][0]);
    for (int64 v : adj[u])
    {
        int64 m = dfsMax(v);
        if (m >= maxBranch[u])
        {
            maxBranch[u] = m;
            maxBranchIdx[u] = v;
        }
        if (m <= minBranch[u])
        {
            minBranch[u] = m;
            minBranchIdx[u] = v;
        }
    }
    return max(F[u], maxBranch[u]);
}
void solve()
{
    // Tree structure
    // Leaves are initiator
    // Dfs traversal
    // While traversing, we will go to the branch with minimum max
    // So the children should be sorted in increasing order of there maximum. No need to be sorted. We just need the index of highest max.
    // After reaching the leaf we will add the maximum value in the path from root to leaf in the result
    // From a node after going to first child max will be zero
    // Creating a virtual root which has a value 0
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> F[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        adj[P[i]].push_back(i);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j : adj[i])
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    dfsMax(0);
    ans = 0;
    dfs(0, 0);
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << maxBranch[i] << ' ';
    // }
    // cout << endl;
}
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
        printf("Case #%d: %d\n", t, ans);
    }
    return EXIT_SUCCESS;
}
