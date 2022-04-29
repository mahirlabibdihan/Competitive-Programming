/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B    D I H A N

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
    // For strings we need to remember that there is only 26 alphabets.
    // So we can follow bruteforce
    string s;
    cin >> s;
    // We need to store the indexes of each letter.
    vector<set<int>> idx(26);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        idx[s[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            idx[s[pos - 1] - 'a'].erase(pos - 1);
            s[pos - 1] = c;
            idx[c - 'a'].insert(pos - 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int count = 0;
            for (int i = 0; i < 26; i++)
            {
                auto itr = idx[i].lower_bound(l - 1);
                if (itr != idx[i].end() && *itr < r)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}
int main()
{
    FAST_IO;
    int T;
    // cin >> T;
    // for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
