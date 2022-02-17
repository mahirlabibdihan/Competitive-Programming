#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

int DP(int n, int k)
{
    int dp[n + 1][k + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            for (int p = i; p <= n; p += i)
            {
                dp[p][j + 1] = (dp[p][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count = (count + dp[i][k]) % MOD;
    }
    return count;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << DP(n, k);
}
