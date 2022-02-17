#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define MOD 1000000007
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// We will create come connected graphs
// Number of possible way to color a graph using at most m colors

int64 dfs(vector<set<int>> adj, int u, int m, int prev, vector<bool> &visited)
{
    visited[u] = true;
    int64 count = (m - adj[u].size());
    // cout << u << " " << adj[u].size() << endl;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            count = (count * dfs(adj, v, m, u, visited)) % MOD;
        }
    }
    // cout << count << endl;
    return count;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    vector<set<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].insert(a[i] - 1);
        adj[a[i] - 1].insert(i);
    }
    vector<bool> visited(n);
    int64 result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            int64 count = m;
            for (int v : adj[i])
            {
                if (!visited[v])
                {
                    count = (count * dfs(adj, v, m, i, visited)) % MOD;
                }
            }
            result += count;
            // cout << count << endl;
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // cout << i << endl;
            int count = 0;
            int64 pro = 1;
            queue<int> q;
            visited[i] = true;
            q.push(i);
            while (!q.empty())
            {
                pro = (pro * (m - count)) % MOD;
                cout << m - count << endl;
                count++;
                int v = q.front();
                q.pop();
                for (int w : adj[v])
                {
                    if (!visited[w])
                    {
                        visited[w] = true;
                        q.push(w);
                    }
                }
            }
            result = (result + pro) % MOD;
        }
    }*/
    cout << result << endl;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
