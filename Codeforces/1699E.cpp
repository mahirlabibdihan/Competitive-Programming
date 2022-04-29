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
    // 11 different letters
    // 2 position
    // 11^2 posibble combination
    // Two option:
    // First letter matches
    // Second letter matches
    // Sort based on first and second letter
    map<char, map<char, int>> countS;
    map<char, int> countF;
    map<char, map<char, int>> countS2;
    map<char, int> countF2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char a, b;
        cin >> a >> b;
        countF[a]++;
        countS[a][b]++;
        countF2[b]++;
        countS2[b][a]++;
    }
    uint64 result = 0;
    for (char i = 'a'; i <= 'k'; i++)
    {
        uint64 sum = countF[i];
        // cout << sum << " " << result << endl;
        for (char j = 'a'; j <= 'k'; j++)
        {
            sum -= countS[i][j];
            result += countS[i][j] * sum;
        }
    }
    for (char i = 'a'; i <= 'k'; i++)
    {
        uint64 sum = countF2[i];
        // cout << sum << " " << result << endl;
        for (char j = 'a'; j <= 'k'; j++)
        {
            sum -= countS2[i][j];
            result += countS2[i][j] * sum;
        }
    }
    cout << result << endl;
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
aa
ab
cb
cc
db
ef
*/