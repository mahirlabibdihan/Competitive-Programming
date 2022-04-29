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
vector<int64> a(400);
int64 N, D;
map<tuple<int64, int64, int64>, int64> dp;
int64 DP(int64 l, int64 r, int64 d)
{
    tuple<int64, int64, int64> tuple1(l, r, d);
    if (dp.find(tuple1) == dp.end())
    {
        if (l == 0 && r == N - 1)
        {
            int64 cost = min(d, D - d);
            dp[tuple1] = cost;
        }
        else
        {
            dp[tuple1] = LLONG_MAX;
            if (l > 0)
            {
                int64 cost = abs(a[l - 1] - d);
                if (d > a[l - 1])
                {
                    cost = min(cost, D + (a[l - 1] - d));
                }
                else
                {
                    cost = min(cost, D - (a[l - 1] - d));
                }
                dp[tuple1] = min(dp[tuple1], cost + DP(l - 1, r, a[l - 1]));
            }
            if (r < N - 1)
            {
                int64 cost = abs(a[r + 1] - d);
                if (d > a[r + 1])
                {
                    cost = min(cost, D + (a[r + 1] - d));
                }
                else
                {
                    cost = min(cost, D - (a[r + 1] - d));
                }
                dp[tuple1] = min(dp[tuple1], cost + DP(l, r + 1, a[r + 1]));
            }
        }
    }
    return dp[tuple1];
}
int64 solve()
{
    // make range [l,r] equal to adjacent
    // If adjacent are different choose the closer one
    // N <= 400 -> Bruteforce(DP)
    dp.clear();
    int64 minMove = LLONG_MAX;
    for (int64 i = 0; i < N; i++)
    {
        minMove = min(minMove, DP(i, i, a[i]));
    }
    return minMove;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> D;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return EXIT_SUCCESS;
}

/*
3,3 - 1
2,4 - 0
0,5 - 1
*/