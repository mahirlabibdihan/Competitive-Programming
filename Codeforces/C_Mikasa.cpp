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
void solve(int n, int m)
{
    int k = n;
    bool flag = false;
    for (int i = 0, mask = 1 << 29; i <= 29; i++, mask >>= 1)
    {
        if ((n & mask) > 0 && (m & mask) > 0)
        {
        }
        else if ((m & mask) > 0)
        {
            k = k | mask;
        }
        else if ((n & mask) > 0)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        for (int i = 0, mask = 1; i <= 29; i++, mask <<= 1)
        {
            if ((k & mask) == 0)
            {
                k = k | mask;
                break;
            }
            else if ((n & mask) == 0)
            {
                k = k ^ mask;
            }
        }
    }
    cout << (k ^ n) << endl;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return EXIT_SUCCESS;
}
