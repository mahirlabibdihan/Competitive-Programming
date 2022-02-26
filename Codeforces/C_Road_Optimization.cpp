#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int solve(vector<int> d, vector<int> a, int n, int l, int k)
{
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n + 1), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(d, a, n, l, k) << endl;
}
