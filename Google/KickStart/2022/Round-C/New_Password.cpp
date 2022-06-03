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
bool hasUpperCase(string s)
{
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            return true;
        }
    }
    return false;
}
bool hasLowerCase(string s)
{
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            return true;
        }
    }
    return false;
}
bool hasDigit(string s)
{
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            return true;
        }
    }
    return false;
}
bool hasSpecialChar(string s)
{
    for (char c : s)
    {
        if (c == '#' || c == '@' || c == '*' || c == '&')
        {
            return true;
        }
    }
    return false;
}
string solve(string s, int n)
{
    if (!hasUpperCase(s))
    {
        s += 'A';
    }
    if (!hasLowerCase(s))
    {
        s += 'a';
    }
    if (!hasDigit(s))
    {
        s += '0';
    }
    if (!hasSpecialChar(s))
    {
        s += '#';
    }
    while (s.length() < 7)
    {
        s += '0';
    }
    // cout << s << endl;
    return s;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // string res = solve(s, n);
        // cout << "Case #" << t << ": " << s << '\n';
        cout << "Case #" << t << ": " << solve(s, n) << endl;
        // cout << solve(s, n) << '\n';
    }
    return EXIT_SUCCESS;
}
