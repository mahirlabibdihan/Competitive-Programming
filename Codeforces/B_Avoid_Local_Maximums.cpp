#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            count++;
            if (i == n - 2)
            {
                a[i + 1] = a[i];
            }
            else
            {
                a[i + 1] = max(a[i], a[i + 2]);
            }
        }
    }
    cout << count << endl;
    for (int i : a)
    {
        cout << i << " ";
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
