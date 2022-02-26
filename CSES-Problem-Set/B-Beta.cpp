#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        // cout << dp[i] << " ";
    }
    cout << dp[n] << endl;
}