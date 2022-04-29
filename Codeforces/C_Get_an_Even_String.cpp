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
string s;
int n;
int64 dp[200000][26];
int64 DP(int i, char prev, int len)
{
    if (i == n)
    {
        if (len % 2 == 0)
        {
            return 0;
        }
        else
        {
            // cout << prev << "  " << len << endl;
            return -1;
        }
    }
    if (prev != -1)
    {
        if (dp[i][prev - 'a'] == -1)
        {
            if (len % 2 == 0)
            {
                int64 inc = DP(i + 1, s[i], len + 1);
                int64 exc = DP(i + 1, prev, len);
                if (inc != -1 && exc != -1)
                {
                    dp[i][prev - 'a'] = min(inc, 1 + exc);
                }
                else if (inc != -1)
                {
                    dp[i][prev - 'a'] = inc;
                }
                else if (exc != -1)
                {
                    dp[i][prev - 'a'] = 1 + exc;
                }
                else
                {
                    dp[i][prev - 'a'] = -1;
                }
            }
            else
            {
                if (s[i] == prev)
                {
                    dp[i][prev - 'a'] = DP(i + 1, s[i], len + 1);
                }
                else
                {
                    int64 exc = DP(i + 1, prev, len);
                    if (exc != -1)
                    {
                        dp[i][prev - 'a'] = 1 + exc;
                    }
                    else
                    {
                        dp[i][prev - 'a'] = -1;
                    }
                }
            }
        }
        // cout << dp[i][prev - 'a'] << endl;
        return dp[i][prev - 'a'];
    }
    else
    {
        int64 inc = DP(i + 1, s[i], len + 1);
        int64 exc = DP(i + 1, prev, len);
        if (inc != -1 && exc != -1)
        {
            return min(inc, 1 + exc);
        }
        else if (inc != -1)
        {
            return inc;
        }
        else if (exc != -1)
        {
            return 1 + exc;
        }
        else
        {
            return -1;
        }
    }
}
void solve()
{
    cin >> s;
    n = s.length();
    map<char, int> idx;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (idx.find(s[i]) != idx.end())
        {
            len += 2;
            idx.clear();
        }
        else
        {
            idx[s[i]] = i;
        }
    }
    cout << n - len << endl;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
