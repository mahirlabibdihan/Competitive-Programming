// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);

vector<int> parent(100000);
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
// Driver code
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    map<int, int> idx;
    for (int &i : a)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        idx[a[i]] = i;
    }
    int count = 0;
    int last = -1;
    // vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    map<int, int> parent;
    for (int i = 0; i < n; i++)
    {
        if (last == -1 || a[i] > a[last])
        {
            // cout << i << endl;
            last = i;
            count++;
            visited[i] = true;
            parent[a[i]] = last;
            for (int j = 1; j < a[last]; j++)
            {
                if (idx[j] > i)
                {
                    if (parent[j] != last && visited[parent[j]])
                    {
                        visited[parent[j]] = false;
                        count--;
                    }
                    parent[j] = last;
                }
            }
        }
        // cout << i << " " << last << " " << count << endl;
    }
    // cout << endl;
    cout << count << endl;
    return;
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
