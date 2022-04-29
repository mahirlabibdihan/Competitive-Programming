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
// int DnC(string s, int n, char even, char odd, int count)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
// }
// int maxCount = 0;
void solve()
{
    // t[0]t[1]t[2]....t[n-1]t[n]

    // t[1]t[2]t[3]t[4]....t[n]t[0]
    // t[n]t[0]t[1]t[2]....t[n-2]t[n-1]
    // t[0]==t[2]==t[n-1]
    // t[1]==t[n]
    // Even positions will be equal
    // Odd positions will be equal
    // There can be atmost two distinct digit in the number
    // abababab or aaaa
    // If there is two distinct digits length of th number must be even

    // Two cases
    // 1 digit: Digit with maximum frequency
    // 2 digits:
    string s;
    cin >> s;
    int maxCount = 0;
    for (int i = '0'; i <= '9'; i++)
    {
        for (int j = '0'; j <= '9'; j++)
        {
            int count = 0;
            for (char c : s)
            {
                if (count % 2 == 0 && c == i)
                {
                    count++;
                }
                else if (count % 2 == 1 && c == j)
                {
                    count++;
                }
            }
            if (i != j)
            {
                maxCount = max(maxCount, 2 * (count / 2));
            }
            else
            {
                maxCount = max(maxCount, count);
            }
        }
    }
    cout << s.length() - maxCount << endl;
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
// 1010