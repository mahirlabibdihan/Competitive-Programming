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
int solve(vector<int> a, int n)
{
    // Maximum sorted
    int l = 0, r = n - 1;
    vector<int> result;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        if (a[l] <= a[r])
        {
            if (result.empty() || a[l] >= result.back())
                result.push_back(a[l]);
            l++;
        }
        else
        {
            if (result.empty() || a[r] >= result.back())
                result.push_back(a[r]);
            r--;
        }
    }
    return result.size();
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
        vector<int> a(n);
        cin >> a;
        cout << "Case #" << t << ": " << solve(a, n) << endl;
    }
    return EXIT_SUCCESS;
}
