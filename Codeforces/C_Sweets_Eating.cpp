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
    int64 n, m;
    cin >> n >> m;
    vector<int64> a(n);
    cin >> a;
    sort(a.begin(), a.end(), greater<int>());
    int64 sum = 0;
    int64 tmpSum = 0;
    for (int i = 0; i < n; i++)
    {
        tmpSum += a[i];
        if ((i + 1) % m == 0)
        {
            sum += tmpSum * ((i + 1) / m);
            tmpSum = 0;
        }
    }
    sum += tmpSum * ceil(1.0 * (n) / m);
    vector<int64> result(n);
    result[n - 1] = sum;
    
    vector<int64> preSum(m, 0);
    for (int i = 0; i < n; i++)
    {
        preSum[i % m] += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int64 s = 0;
        s = preSum[i % m];
        result[n - i - 2] = result[n - i - 1] - s;
        preSum[i % m] -= a[i];
    }
    cout << result << endl;
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
