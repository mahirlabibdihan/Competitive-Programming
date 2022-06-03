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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    // cout << a << endl;
    // We will first change the unique values, and keep the duplicates as long as possible
    // After finishing the unique values we will hit the duplicate ones

    // First find the mex
    vector<bool> b(n, false);
    for (int i : a)
    {
        if (i < n)
            b[i] = true;
    }
    int c = 0;
    int j = n;
    for (int i = 0; i < n; i++)
    {
        if (!b[i])
        {
            c++;
        }
        if (c == k)
        {
            j = i + 1;
            for (; j < n; j++)
            {
                if (!b[j])
                {
                    break;
                }
            }
            break;
        }
    }
    int mex = j;
    if (mex == n)
    {
        cout << 0 << endl;
        return;
    }
    map<int, int> count;
    int unq = 0;
    for (int i : a)
    {
        count[i]++;
        if (count[i] == 1)
        {
            unq++;
        }
    }
    c = 0;
    // cout << a << endl;
    // cout << "Start" << endl;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mex)
        {
            if (count[a[i]] == 1)
                // cout << a[i] << endl;
                c++;
        }
    }
    if (c >= k)
    {
        cout << unq - mex << endl;
    }
    else
    {
        k -= c;
        int64 res = unq - mex;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mex)
            {
                if (count[a[i]] > 1)
                // cout << a[i] << endl;
                {
                    if (k >= count[a[i]])
                    {
                        k -= count[a[i]];
                        res += count[a[i]] - 1;
                    }
                    else
                    {
                        res += k;
                        k = 0;
                    }
                }
            }
            // cout << res << " " << mex << endl;
        }
        if (k)
        {
            res += k;
        }
        cout << res << endl;
    }
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
