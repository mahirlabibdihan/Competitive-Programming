#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

void solve()
{
    int64 n, x;
    cin >> n >> x;
    int64 a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int64, int64>> v;
    int64 total_max = LLONG_MIN;
    for (int len = 1; len <= n; len++)
    {
        int64 sum = 0;
        int64 mx = LLONG_MIN;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            if (i > len)
            {
                sum -= a[i - len];
            }
            if (i >= len)
                mx = max(mx, sum);
        }
        v.push_back({mx, len});
    }
    sort(v.rbegin(), v.rend());
    cout << max(0LL, v[0].first) << " ";
    for (int64 k = 1; k <= n; k++)
    {
        int64 ans = LLONG_MIN;

        for (auto i : v)
        {
            int64 len = i.second;
            int64 val = i.first;

            if (k <= len)
            {
                val = val + x * k;
            }
            else
            {
                val = val + x * len;
            }
            ans = max(ans, val);
        }

        cout << max(ans, 0LL) << " ";
    }
    cout << endl;
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
