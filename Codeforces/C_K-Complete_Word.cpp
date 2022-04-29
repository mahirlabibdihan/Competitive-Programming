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
void solve()
{
    int n, k; //  k <= n/2
    cin >> n >> k;
    // s should be pallindrome
    // And substring of length k should repeat n/k times
    // Substring of length k should also be pallindrome
    // Need to find the minimum moves to make k pallindrome
    string s;
    cin >> s;
    vector<vector<int>> a(k, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        a[i % k][s[i] - 'a']++;
    }
    int64 result = 0;
    for (int i = 0, j = k - 1; i <= j; i++, j--)
    {
        int m = 0;
        for (int k = 0; k < 26; k++)
        {
            if (i != j)
            {
                m = max(m, a[i][k] + a[j][k]);
            }
            else
            {
                m = max(m, a[i][k]);
            }
        }
        if (i != j)
        {
            result += (2 * n / k) - m;
        }
        else
        {
            result += (n / k) - m;
        }
    }
    cout << result << endl;
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
// wudixia
// oxingxi
// ngheclp

// (6-1)+(6-2)+(6-1)+(3-1)
// axxixxa
// axxixxa
// axxixxa

// hippopoto
// monstrose
// squippeda
// liophobia