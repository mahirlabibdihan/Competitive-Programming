#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// 2nd number of each pair must be divided by x
// After dividing the 2nd number by x, frequency of each number array must be even
// The numbers which are not divisible by x, they must be first number of pair
// If a[i] is not divisible by x, then x*a[i] also must be present in the array
// If not we have to add that
// Problem is when a number is divisible by x, but it is the first element of pair
// If a[i] is divisible by x, then a[i]/x must be available in the array
// Or x*a[i] must be available
// If not, we have to add a number
// If both a[i]/x and a[i]*x is available. Then what to do?
// If we sort the array, there is no chance of a[i]/x's availability
void solve()
{
    int64 n, x;
    cin >> n >> x;
    vector<int64> a;
    map<int64, int> count;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (count.find(tmp) == count.end())
        {
            a.push_back(tmp);
            count[tmp] = 1;
        }
        else
        {
            count[tmp]++;
        }
    }
    sort(a.begin(), a.end());
    int m = a.size();
    int64 c = 0;
    for (int i : a)
    {
        if (count.find(i * x) == count.end())
        {
            c += count[i];
        }
        else if (count[i] > count[i * x])
        {
            c += count[i] - count[i * x];
            count[i * x] = 0;
        }
        else
        {
            count[i * x] -= count[i];
        }
    }
    cout << c << endl;
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
