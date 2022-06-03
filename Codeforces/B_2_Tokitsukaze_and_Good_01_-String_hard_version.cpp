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
    // Adjacent odd - 1
    // No adjacent - 2
    // # of odd segment will be even
    int n;
    cin >> n;
    string s;
    cin >> s;
    char curr = s[0];
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == curr)
        {
            count++;
        }
        else
        {
            if (count % 2)
            {
                res++;
                count++;
            }
            else
            {
                curr = s[i];
                count = 1;
            }
        }
    }
    vector<int> seg;
    count = 1;
    curr = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == curr)
        {
            count++;
        }
        else
        {
            seg.push_back(count);
            count = 1;
            curr = s[i];
        }
    }
    seg.push_back(count);

    // First and last 1 -> Remove that
    // Middle 2
    int c = 0;
    int m = seg.size();
    int last = -1;
    bool twoExists = false;
    for (int i = 0; i < m; i++)
    {
        if (seg[i] % 2)
        {
            if (last == -1)
            {
                last = i;
            }
            else
            {
                if (twoExists)
                {
                    c += 2;
                    if (i - last > 2)
                    {
                    }
                }
                else
                {
                    if (seg[last] == 1)
                    {
                        c++;
                    }
                    if (seg[i] == 1)
                    {
                        c++;
                    }
                }
                last = -1;
            }
            twoExists = false;
            cout << c << endl;
        }
        else
        {
            if (seg[i] == 2)
            {
                twoExists = true;
            }
        }
    }
    if (last != -1)
    {
        if (seg[last] == 1)
        {
            c++;
        }
    }
    cout << res << " " << seg.size() - c << endl;
    // cout << res << " " << seg << endl;
    // If a 2 exists between two odd
    // 1111111111
    // 00110
    // 00111111
    // 110000000011
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