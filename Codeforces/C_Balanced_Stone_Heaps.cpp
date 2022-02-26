#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// The last heap won't increase
// And the first two heaps won't decrease
// Stones from 3 to n will decrease maximum 3*(h[i]/3)
// Stones from 2 to n-2 will increase maximum 2*(h[i+2]/3)+(h[i+1]/3)
// Stone 1 will increase maximum 2*(h[3]/3)
// Stone n-1 will increase maximum (h[n]/3)

// min(h)<=ans<max(h)
bool check(vector<int> h, int n, int x)
{
    vector<int> tmp(h.begin(), h.end());
    for (int i = n - 1; i >= 2; i--)
    {
        if (tmp[i] < x)
        {
            return false;
        }
        int d = min(h[i], tmp[i] - x) / 3;
        tmp[i - 1] += d;
        tmp[i - 2] += 2 * d;
    }
    return tmp[0] >= x && tmp[1] >= x;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> h(n);
    int l = INT_MAX;
    int r = INT_MIN;
    for (int &i : h)
    {
        cin >> i;
        l = min(l, i);
        r = max(r, i);
    }
    // cout << l << " " << r << endl;
    while (l + 1 < r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (check(h, n, mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}