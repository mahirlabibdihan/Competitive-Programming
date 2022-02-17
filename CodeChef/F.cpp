#include <iostream>
#include <vector>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// N<=K<=N(N+1)/2
void solve()
{
    int64 n, k;
    cin >> n >> k;

    // 3
    // 2
    // 1
    // Max size good subarray -> g
    // g*(g+1)/2 <= k
    int64 g, t = n;
    int64 sum = 0;
    for (g = 1; sum + t < k && t >= 1; g++, t--)
    {
        sum += t;
    }

    int64 count = k - sum;
    // cout << g << " " << k - sum << endl;
    vector<int64> result;
    for (int64 i = 1; i <= g; i++)
    {
        result.push_back(i);
    }
    for (int64 i = 1, j = 1; i < count; i++, j = (j == g ? 1 : j + 1))
    {
        result.push_back(j);
    }

    int64 pivot = result.size() - (g - 1);
    for (int64 i = pivot; result.size() < n; i = (i == pivot + g - 2 ? pivot : i + 1))
    {
        result.push_back(result[i]);
    }
    for (int64 i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    // 1 2 3 4 1 2 4 1 2
    // 4 5
    // 4 5
    // k = n*(n+1)/2 -> A = {All elements from 1 to N}
    // k = n -> A={All the elements will be same}

    // 10 -> 1*3 + 2*4 + 1*5
    // 1 2 1 2 2
    // 1 1 1 1 1 -> n
    // 1 1 1 1 2 -> n+1 (All same except the first or last)
    // 1 1 1 2 1 -> n+2 (All same except any middle one)
    // 1 2 1 2 1 -> n+(n-1)
    // 1 2 3 1 2
    // 1 2 3 4 1
    // 1 2 3 4 1 2
    // 1 | | | | |
    // 2 | | | |
    // 3 | | |
    // 4 | |
    // 5
    // 2*(n-1)
    // .... n*1
    // n + n-1 +
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
