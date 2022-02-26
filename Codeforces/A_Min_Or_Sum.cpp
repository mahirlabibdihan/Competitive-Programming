#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

bool isSet(int n, int i)
{
    return (n & (1 << i));
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k <= 30; k++)
            {
                if (isSet(a[i], k) && isSet(a[j], k))
                {
                    a[i] = a[i] ^ (1 << k);
                }
            }
        }
    }
    int64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
        sum += a[i];
    }
    cout << sum << endl;
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
