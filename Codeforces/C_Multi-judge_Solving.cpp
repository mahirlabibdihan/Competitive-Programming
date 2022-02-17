#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solve(vector<int> a, int n, int k)
{
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 2 * k)
        {
            count += floor(log2((a[i] - 1) / k));
        }
        if (a[i] > k)
        {
            k = a[i];
        }
    }
    return count;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(a, n, k);
}
