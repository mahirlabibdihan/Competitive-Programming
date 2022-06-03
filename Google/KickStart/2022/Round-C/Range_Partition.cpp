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
vector<int> solve(int n, int x, int y)
{
    int sum = n * (n + 1) / 2;
    if (sum % (x + y) == 0)
    {
        int k = sum / (x + y);
        x *= k;
        y *= k;
        vector<int> result;
        for (int i = n; i >= 0 && x > 0; i--)
        {
            if (i <= x)
            {
                result.push_back(i);
                x -= i;
            }
        }
        return result;
    }
    else
    {
        return vector<int>();
    }
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> res = solve(n, x, y);
        cout << "Case #" << t << ": ";
        if (res.size() == 0)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "POSSIBLE" << endl;
            // cout
            cout << res.size() << endl;
            for (int i : res)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return EXIT_SUCCESS;
}
