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
    stack<int> p;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> m(n, -1);
    int lastLength = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (!p.empty())
            {
                // cout << "Valid: ( " << p.top() << "," << i << " )" << endl;
                m[p.top()] = i;
                // lastLength = i - p.top() + 1;
                p.pop();
            }
            else
            {
                // if (lastLength != -1)
                // {
                //     validLength += lastLength;
                //     nOpr++;
                //     lastLength = -1;
                // }
                // cout << "Invalid at " << i << endl;
            }
        }
        else
        {
            p.push(i);
        }
    }
    // if (lastLength != -1)
    // {
    //     validLength += lastLength;
    //     nOpr++;
    //     lastLength = -1;
    // }
    int validLength = 0;
    int nOpr = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << i << endl;
        for (int j = i; j < n; j++)
        {
            if (m[j] != -1)
            {
                // cout << "Forward" << i << " " << j << endl;
                j = m[j];
                // cout << "Forward" << i << " " << j << endl;
            }
            else
            {
                // cout << "End" << i << " " << j << endl;
                validLength += j - i;
                if (j > i)
                {
                    nOpr++;
                }
                else
                {
                    // cout << i << " " << j << endl;
                }
                i = j;
                break;
            }
            if (j == n - 1)
            {
                if (j > i)
                {
                    validLength += j - i + 1;
                    nOpr++;
                }
                i = j;
                break;
            }
        }
    }
    cout << n - validLength << " " << nOpr << endl;
    // cout << endl;
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
