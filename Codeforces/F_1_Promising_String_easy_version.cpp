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
    // Substring is promising if (#minus>#plus)&&(#minus - #plus) = 3a where a=b
    int n;
    cin >> n;
    string s;
    cin >> s;
    int64 res = 0;
    vector<int> preMinus(n + 1), prePlus(n + 1), preNm(n + 1);
    int lastM = 0;
    int nM = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
        {
            preMinus[i + 1] = 1 + preMinus[i];
            prePlus[i + 1] = 0 + prePlus[i];
            nM++;
            preNm[i + 1] = lastM + nM / 2;
        }
        else
        {
            preMinus[i + 1] = 0 + preMinus[i];
            prePlus[i + 1] = 1 + prePlus[i];
            lastM = preNm[i + 1] = preNm[i];
            nM = 0;
        }
    }
    // cout << preNm << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j <= n; j++)
        {
            int c = preNm[j] - preNm[i];
            int nMinus = preMinus[j] - preMinus[i];
            int nPlus = prePlus[j] - prePlus[i];
            res += (nMinus - nPlus >= 0 && ((nMinus - nPlus) % 3 == 0 && (nMinus - nPlus) / 3 <= c));
        }
    }
    cout << res << endl;
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
