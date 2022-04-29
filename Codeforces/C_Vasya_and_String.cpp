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
// Find maximum length subarray with abs(sum) <= k and sum%2==0
int findMaxSubarraySum(vector<int> a, int n, int k)
{
    int maxLen = 0;
    int l = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (abs(sum) > k)
        {
            sum -= a[l];
            l++;
        }
        if (sum % 2)
        {
            maxLen = max(maxLen, i - l + 1);
        }
    }
    return maxLen;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // If we wan make the substring of 'a', then freq['b']<=k
    // If we wan make the substring of 'b', then freq['a']<=k
    int countA = 0, countB = 0;
    int l = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            countA++;
        }
        else
        {
            countB++;
        }
        while (countA > k && countB > k)
        {
            if (s[l] == 'a')
            {
                countA--;
            }
            else
            {
                countB--;
            }
            l++;
        }
        maxLen = max(maxLen, i - l + 1);
    }
    cout << maxLen << endl;
    /*vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a[i] = 1;
        }
        else
        {
            a[i] = -1;
        }
    }
    // cout << a << endl;
    vector<int> sum(n);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((j - i) - abs(sum[j] - sum[i]) <= 2 * k)
            {
                // cout << j << " " << i << " " << j - i << " " << sum[j] - sum[i] << endl;
                maxLen = max(maxLen, j - i);
            }
        }
    }
    cout << maxLen << endl;*/
}
int main()
{
    FAST_IO;
    int T;
    // cin >> T;
    // for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
