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
    // adjacent can increase by 1
    // can decrease by at most n-1
    // adjacent can't be same
    // power - 1 -> Max is at start
    // power - n -> Sorted in increasing order
    // If value is 1 at i-th rotation, then max value was at tail in i-1 th rotation
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        if (b.empty() && a[i] == 1)
        {
            b.push_back(a[i]);
        }
        else if (!b.empty())
        {
            b.push_back(a[i]);
        }
    }
    if (b.empty())
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; b.size() < n; i++)
    {
        b.push_back(a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (b[i] < b[i - 1])
        {
        }
        else if (b[i] == 1)
        {
            cout << "NO" << endl;
            return;
        }
        else if (b[i] - b[i - 1] > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << b << endl;
    
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
/*
1 2 3 4 2 3

1 5 2 3 4 6
*/