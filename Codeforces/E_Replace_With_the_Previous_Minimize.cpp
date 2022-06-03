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
    // We have to make the lower index equal to 'a'
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, char> history;
    history['a'] = 'a';
    vector<bool> mx(n, false);
    char lastMax = 'a' - 1;
    string t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] > lastMax)
        {
            char tmp = s[i];
            t += s[i];
            if (s[i] - k <= (lastMax == 'a' - 1 ? 'a' : lastMax))
            {
                // cout << i << endl;
                k -= (s[i] - (lastMax == 'a' - 1 ? 'a' : lastMax));
                history[s[i]] = history[(lastMax == 'a' - 1 ? 'a' : lastMax)];
                s[i] = history[s[i]];
            }
            else
            {
                history[s[i]] = s[i] - k;
                s[i] = history[s[i]];
                k = 0;
            }
            lastMax = tmp;
        }
    }
    // for (auto m : history)
    // {
    //     cout << m.first << "->" << m.second << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'a')
        {
            for (char c = s[i]; c <= 'z'; c++)
            {
                if (history.find(c) != history.end())
                {
                    history[s[i]] = min(history[c], s[i]);
                    s[i] = history[s[i]];
                    break;
                }
            }
        }
    }
    cout << s << endl;

    // Every index has a parent
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

// ekyv - 19
// akyv - 15
// aayv - 11
// aa
// gn