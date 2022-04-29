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
bool isSuperior(int a[], int b[])
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] < b[i])
        {
            count++;
        }
    }
    return (count >= 3);
}
void solve()
{
    int n;
    cin >> n;
    int r[n][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> r[i][j];
        }
    }
    int m = 0;
    for (int i = 1; i < n; i++)
    {
        if (isSuperior(r[i], r[m]))
        {
            m = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != m)
        {
            if (!isSuperior(r[m], r[i]))
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << m + 1 << endl;
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
