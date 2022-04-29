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
bool isPrime(int64 n) // Fastest
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 | n % 3 == 0)
        return 0;
    int64 i;
    for (i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0)
            return false;
        else if (n % (i + 2) == 0)
            return false;
    }
    return true;
}
void solve()
{
    // Good number - Divisible by d
    // d itself is a good number
    // Beautiful - Divisible by d only once
    // x should be divisible by d multiple times.
    // If x is divisible by d n times.
    // We can make maximum n beautiful numbers.
    // If d is prime we have to make exactly n beautiful numbers.
    // No number can be common in two different ways
    //
    int64 x, d;
    cin >> x >> d;

    if (x % d == 0)
    {
        int64 rem = x / (d * d);
        cout << rem << " " << d << endl;
        if (rem % d == 0)
        {
            // If there are d's left in rem, then we need to divide them into two parts.
            // So that d vanishes from
            if (isPrime(d)) // Can't vanish d
            {
                cout << "NO" << endl;
            }
            else
            {
                // We can use parts of d as coefficient
                if (isPrime(rem / d))
                {
                    cout << "NO" << endl;
                }
            }
        }
        else if (isPrime(rem))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
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
