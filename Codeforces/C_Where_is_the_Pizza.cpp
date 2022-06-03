
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

typedef long long ll;
/**********************************************/

/************ SOLUTION *************/
#define MOD 1000000007
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), c(n);
        cin >> a >> b >> c;
        // Need to find out the number of cycles
        // If any slot of the cycle is already in c,then one option for that
        vector<ll> adj(n + 1);
        vector<bool> taken(n + 1);
        for (int i = 0; i < n; i++)
        {
            adj[a[i]] = b[i];
            taken[c[i]] = true;
        }
        // cout << adj << endl;
        vector<bool> visited(n + 1, false);
        ll res = 1;
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            bool flag = true;
            if (!visited[j])
            {
                int sz = 0;
                while (!visited[j])
                {
                    // cout << j << " ";
                    visited[j] = true;
                    if (taken[j])
                    {
                        flag = false;
                    }
                    // cout << j << " " << adj[adj[j]] << endl;
                    j = adj[j];
                    sz++;
                }
                // cout << j << endl;
                if (flag && sz > 1)
                {
                    res = (res * 2) % MOD;
                }
            }
        }
        cout << res << endl;
    }
    return EXIT_SUCCESS;
}
