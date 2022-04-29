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
    // We may need to sort the array in increasing order
    // freopen("output.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    // Now we need to find out c, for which a[i] = c^i
    // 1 , c , c*c , c*c*c .... , c*c*..*c <10^10
    // cout << a << endl;
    int64 minCost = LLONG_MAX;
    for (int i = 1;; i++)
    {
        int64 cost = 0;
        int64 c = 1;
        for (int j = 0; j < n; j++, c *= i)
        {
            cost += abs(a[j] - c);
            if (c > 100000000000000LL)
            {
                goto X;
            }
        }

        if (minCost > cost)
        {
            // cout << i << " " << cost << endl;
            minCost = cost;
        }
    }
X:
    cout << minCost << endl;
}
int main()
{
    FAST_IO;
    // int T;
    // cin >> T;
    // for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
