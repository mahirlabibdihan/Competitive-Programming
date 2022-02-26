#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// We will try to give the same power ups to the same child
// Distinct power ups can be distributed to anyone
// But same power ups will
void solve()
{
    // Assume there are m unique power ups
    // So strength from k=1 to k=m will be m
    // After that increases one
    int n;
    cin >> n;
    set<int> a;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    int m = a.size();
    for (int k = 1; k <= m; k++)
    {
        cout << m << " ";
    }
    for (int k = m + 1; k <= n; k++)
    {
        cout << k << " ";
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
