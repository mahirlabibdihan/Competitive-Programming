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
    for (int &i : a)
    {
        cin >> i;
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            l = i;
            break;
        }
    }
    if (l != -1)
    {
        for (int i = l; i < n; i++)
        {
            if (a[i] == l + 1)
            {
                r = i;
                break;
            }
        }
        // cout << l << " " << r << endl;
        reverse(a.begin() + l, a.begin() + r + 1);
    }
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
