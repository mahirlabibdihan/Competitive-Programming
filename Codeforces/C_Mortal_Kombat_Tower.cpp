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
vector<int> a(200000);
int n;
int dp[200001][2] = {};
int DnC(int pos, int step)
{
    // cout << pos << " " << step << endl;
    if (pos < n)
    {
        if (dp[pos][step] == -1)
        {
            int one = 0;
            if (a[pos] == 1)
                one++;
            int tmp1 = (step % 2 == 0 ? one : 0) + DnC(pos + 1, step ^ 1);
            if (pos + 1 < n)
            {
                if (a[pos + 1] == 1)
                    one++;
                int tmp2 = (step % 2 == 0 ? one : 0) + DnC(pos + 2, step ^ 1);
                dp[pos][step] = min(tmp1, tmp2);
            }
            else
            {
                dp[pos][step] = tmp1;
            }
        }
        return dp[pos][step];
    }
    return 0;
}
// vector<int> a(200000);
// int n;
// int DnC(int pos, int step)
// {
//     int one = 0;
//     if (pos < n)
//     {
//         if (a[pos] == 1)
//             one++;
//         int tmp1 = (step % 2 == 0 ? one : 0) + DnC(pos + 1, step ^ 1);
//         if (pos < n)
//         {
//             if (a[pos] == 1)
//                 one++;
//             int tmp2 = (step % 2 == 0 ? one : 0) + DnC(pos + 2, step ^ 1);
//             return min(tmp1, tmp2);
//         }
//         return tmp1;
//     }
//     return 0;
// }
void solve()
{
    // I will try to get maximum number of 1
    // In each step two options: 1 or 2 number in one step
    // Minimum one for friend
    // Maximum one for me
    // Min max
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << DnC(0, 0) << endl;
}
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
