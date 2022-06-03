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
vector<bool> pallindrome(40000);
void preProcess()
{
    for (int i = 1; i < 10; i++)
    {
        pallindrome[i] = true;
    }
    for (int i = 11; i < 100; i += 11)
    {
        pallindrome[i] = true;
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 101 * i; j < (i + 1) * 100; j += 10)
        {
            pallindrome[j] = true;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1001 * i; j < (i + 1) * 1000; j += 110)
        {
            pallindrome[j] = true;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 10001 * i; j < 10001 * i + 1000; j += 100)
        {
            for (int k = j; k < (i + 1) * 10000; k += 1010)
            {
                pallindrome[k] = true;
            }
        }
    }
}
void solve()
{
    // 1 2 3..-> 9
    // 11 , 22, 33, ... -> 9
    // 101,111,121,..,202,212,...303,... -> 9*10
    // 1001,1111,1221,... -> 9*10
    // 10001,10101,10201,--> 10
    // 11011,11111,11211,--> 10
    // 12021
    // 10*10
    // 4*10*10
    // 9+9*1+9*10+4*10*10

    // At most n partition
    // At least 1 partition
    
}
int main()
{
    FAST_IO;
    preProcess();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
