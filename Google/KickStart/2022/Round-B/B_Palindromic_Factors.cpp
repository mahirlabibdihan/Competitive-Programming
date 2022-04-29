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
int isPallindrome(int64 n)
{
    int64 original = n;
    int64 reversed = 0;
    while (n != 0)
    {
        int64 remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return (original == reversed);
}
int countPalindromeDivisors(int64 n)
{
    // Note that this loop runs till square root
    int count = 0;
    for (int64 i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            count += isPallindrome(i);
            if (n / i != i)
                count += isPallindrome(n / i);
        }
    }
    return count;
}
void solve()
{
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int64 n;
        cin >> n;
        cout << "Case #" << t << ": " << countPalindromeDivisors(n) << '\n';
    }
    return EXIT_SUCCESS;
}
