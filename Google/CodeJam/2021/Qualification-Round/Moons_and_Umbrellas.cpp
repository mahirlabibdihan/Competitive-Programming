// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Works for positive x,y
// For test 1 and 2
int getMinCost_Greedy(string s, int x, int y)
{
    char lastChar = '\0';
    int minCost = 0;
    for (char c : s)
    {
        if (c != '?')
        {
            if (lastChar == 'J' && c == 'C')
            {
                minCost += y;
            }
            else if (lastChar == 'C' && c == 'J')
            {
                minCost += x;
            }
            lastChar = c;
        }
    }
    return minCost;
}

// Works for all
// For test 1,2,3
int getMinCost_DP(string s, int x, int y)
{
    int n = s.length();
    int dp[1000][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i][1] = INT_MAX;
    }
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // Thus it will also handle '?'
        if (s[i] != 'J') // C
        {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);     // CC | ?C
            dp[i + 1][1] = min(dp[i + 1][1], x + dp[i][0]); // CJ | ?C
        }
        if (s[i] != 'C') // J
        {
            dp[i + 1][0] = min(dp[i + 1][0], y + dp[i][1]); // JC | ?C
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1]);     // JJ | ?J
        }
    }
    if (s[n - 1] == 'C')
    {
        return dp[n - 1][0];
    }
    if (s[n - 1] == 'J')
    {
        return dp[n - 1][1];
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int x, y; // 1<= x,y <= 100
        string s; // 1<= |S| <= 1000
        cin >> x >> y >> s;
        printf("Case #%d: %d\n", t, getMinCost_DP(s, x, y));
    }
}