#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;
#define MOD 1000000007
// First condition will handle 1 to n
// Second condition will handle odd numbers
// Third condition will handle even numbers
// y<<2
// y<<1|1
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int c = n;

    for (int i = 0; i < n; i++)
    {
        int high = log2(a[i]) + 1;
        c = (c + 1 + ((p - high) / 4) + ((p - high) / 2)) % MOD;
    }
    cout << c << endl;
}
int main()
{
    FASTIO;
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
}
