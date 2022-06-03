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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> pre(n, 0), post(n, 0);
    pre[0] = 0;
    post[n - 1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i])
            {
                pre[i]++;
            }
            else
            {
                post[j]++;
            }
        }
    }
    cout << pre << endl;
    cout << post << endl;
    // 0 0 2 1 4 2 3 7 7 6
    // 4 0 3 0 3 0 0 2 1 0

    // 7*0 + 6*2 + 5*1 + 4*4 + 3*2 + 2*3 + 1*7 + 0*7
    // 0*0 + 1*3 + 2*0 + 3*3 + 4*0 + 5*0 + 6*2 + 7*1

    // 0 0 2 0 2 1
    // 4 2 3 0 1 0

    // 3*0 + 2*1 + 1*0 + 0*2
    // 0*2 + 1*3 + 2*0 + 3*1
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
