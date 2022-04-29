/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <bits/stdc++.h>
using namespace std;

/************* TEMPLATE *************/
#define FAST_IO ios::sync_with_stdio(0), cin.tie(nullptr);
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (T &i : a)
    {
        cin >> i;
    }
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (T &i : a)
    {
        cout << i << " ";
    }
    return out;
}
template <typename T>
void print(T var1)
{
#ifndef ONLINE_JUDGE
    cout << var1 << endl;
#endif
}
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
#ifndef ONLINE_JUDGE
    cout << var1 << " ";
    print(var2...);
#endif
}

typedef long long int64;
typedef unsigned long long uint64;
/**********************************************/

/************ SOLUTION *************/

int n, p;
int64 dp[1000][2]; // 0-l 1-r
vector<vector<int64>> a(1000, vector<int64>(100));
int64 DP(int64 c, int i)
{
    if (i == n)
    {
        return 0;
    }
    if (i > 0)
    {
        if (c == a[i - 1][0])
        {
            if (dp[i][0] == -1)
            {
                dp[i][0] = 0;
                dp[i][0] += a[i][p - 1] - a[i][0];
                dp[i][0] += min(abs(a[i][0] - c) + DP(a[i][p - 1], i + 1),
                                abs(a[i][p - 1] - c) + DP(a[i][0], i + 1));
            }
            return dp[i][0];
        }
        else
        {
            if (dp[i][1] == -1)
            {
                dp[i][1] = 0;
                dp[i][1] += a[i][p - 1] - a[i][0];
                dp[i][1] += min(abs(a[i][0] - c) + DP(a[i][p - 1], i + 1),
                                abs(a[i][p - 1] - c) + DP(a[i][0], i + 1));
            }
            return dp[i][1];
        }
    }
    dp[i][0] = 0;
    dp[i][0] += a[i][p - 1] - a[i][0];
    dp[i][0] += min(abs(a[i][0] - c) + DP(a[i][p - 1], i + 1),
                    abs(a[i][p - 1] - c) + DP(a[i][0], i + 1));
    // cout << c << " " << i << " " << result << " " << a[i][0] << " " << a[i][p - 1] << endl;
    return dp[i][0];
}
int64 solve(vector<vector<int64>> a)
{
    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
        dp[i][0] = dp[i][1] = -1;
        for (int j = 0; j < p; j++)
        {
            ::a[i][j] = a[i][j];
        }
    }
    return DP(0, 0);
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> p;
        vector<vector<int64>> a(n, vector<int64>(p));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "Case #" << t << ": " << solve(a) << endl;
    }
    return EXIT_SUCCESS;
}
/*
10 30 40 -> 40
20 50 60 -> 20 + 40
50 60 60

40 - 20 - 50 - 60 = 20+30+10
40 - 60 - 50 - 20 = 20+10+30

No greedy choice

The last and first ball of a customer matters most.
[l,r] of a customer when sorted
First ball: x
Last ball: y
Total cost: x+(x-l)+(r-l)+(r-y) = 2x + 2r - 2l - y
[l,r] is fixed.
Bruteforce

Each customer will need a cost of atleast (r-l)
*/
