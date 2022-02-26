#include <bits/stdc++.h>
using namespace std;

vector<int64_t> v;
int n;

bool ch()
{
    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i])
            return false;
    return true;
}

void func()
{
    int i;
    cout << n - 2 << endl;
    for (i = 1; i <= n - 2; i++)
        cout << i << ' ' << n - 1 << ' ' << n << endl;
}

void solve()
{
    cin >> n;
    int64_t va;
    for (int i = 0; i < n; i++)
    {
        cin >> va;
        v.push_back(va);
    }
    if (ch())
        cout << 0 << endl;
    else if (v[n - 2] > v[n - 1] || v[n - 2] < 0 && v[n - 1] < 0)
        cout << -1 << endl;
    else
        func();
    v.clear();
}
int main()
{
    int T, i;
    cin >> T;
    while (T--)
    {
        solve();
    }
}