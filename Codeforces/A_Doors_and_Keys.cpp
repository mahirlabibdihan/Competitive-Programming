#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

void solve()
{
    bool r = false, g = false, b = false;
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c == 'R')
        {
            if (!r)
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (c == 'G')
        {
            if (!g)
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (c == 'B')
        {
            if (!b)
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (c == 'r')
        {
            r = true;
        }
        if (c == 'g')
        {
            g = true;
        }
        if (c == 'b')
        {
            b = true;
        }
    }
    cout << "YES" << endl;
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
