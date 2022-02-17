#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);

// a[i]%a[j]<a[j]
// We should approach the larger values first

// a[i] > a[j] ?
// So that we check the numbers after a[j]

// a[i] = k*a[j] + x;
// We need to maximize x;
int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    int maxMod = 0;
    sort(a.begin(), a.end());
    int MAX = a.back();
    vector<bool> visited(MAX + 1, false);
    for (int j = 0; j < n; j++)
    {
        // if (maxMod >= a[j] - 1)
        // {
        //     break;
        // }
        if (visited[a[j]])
            break;
        visited[a[j]] = true;
        for (ll m = 2 * a[j]; m <= 2 * MAX; m += a[j])
        {
            // if (maxMod >= a[j] - 1)
            // {
            //     break;
            // }
            int i = lower_bound(a.begin() + j, a.end(), m) - a.begin() - 1;
            // cout << i << " " << a[i] << " " << m << endl;
            if (i > -1)
            {
                maxMod = max(maxMod, a[i] % a[j]);
            }
        }
    }
    cout << maxMod << endl;
}