#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int64;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
// K operation
// For each operation we have n choices
// O(nk)
int64 POW(int k, int x)
{
    int64 mul = 1;
    while (k--)
    {
        mul *= x;
    }
    return mul;
}
int64 solve(vector<int64> a, int n, int k, int x)
{
    int64 mul = POW(k, x);
    vector<int64> prefix(n + 2, 0), suffix(n + 2, 0);
    int64 maxVal = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = a[i] | prefix[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        suffix[i] = a[i] | suffix[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        maxVal = max(maxVal, prefix[i - 1] | (a[i] * mul) | suffix[i + 1]);
    }
    return maxVal;
}
int main()
{
    FASTIO;
    int n, k, x;
    cin >> n >> k >> x;
    vector<int64> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << solve(a, n, k, x) << endl;
}