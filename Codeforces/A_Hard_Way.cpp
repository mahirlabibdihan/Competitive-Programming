#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

void solve()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((y1 == y2) && y3 < y2)
    {
        cout << abs(x1 - x2) << endl;
    }
    else if (y1 == y3 && y2 < y1)
    {
        cout << abs(x1 - x3) << endl;
    }
    else if (y2 == y3 && y1 < y2)
    {
        cout << abs(x3 - x2) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
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
