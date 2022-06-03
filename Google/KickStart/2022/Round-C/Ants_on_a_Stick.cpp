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
vector<int> solve(vector<tuple<int, int, int>> pd, int n, int l)
{
    sort(pd.begin(), pd.end());
    vector<pair<int, int>> result;
    for (int t = 1; result.size() < n; t++)
    {
        for (int i = 0; i < n; i++)
        {
            if (get<2>(pd[i]) != -1)
            {
                if (get<1>(pd[i]) == 1)
                {
                    if (i < n - 1 && get<1>(pd[i + 1]) == -1 && get<0>(pd[i + 1]) == get<0>(pd[i]) + 1)
                    {
                        swap(get<1>(pd[i]), get<1>(pd[i + 1]));
                        // i--;
                        continue;
                    }
                }
                else
                {
                    if (i > 0 && get<1>(pd[i - 1]) == 1 && get<0>(pd[i - 1]) == get<0>(pd[i]) - 1)
                    {
                        swap(get<1>(pd[i]), get<1>(pd[i - 1]));
                        // get<0>(pd[i - 1]) += get<1>(pd[i - 1]);
                        continue;
                    }
                }
                get<0>(pd[i]) += get<1>(pd[i]);
                if (get<0>(pd[i]) < 0 || get<0>(pd[i]) > l)
                {
                    result.push_back({t, get<2>(pd[i])});
                    // cout << "Removed" << get<2>(pd[i]) << " " << t << endl;
                    get<2>(pd[i]) = -1;
                }
                // for (int k = 0; k < n; k++)
                // {
                //     cout << get<0>(pd[i]) << " ";
                // }
                // cout << endl;
            }
        }
    }
    sort(result.begin(), result.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = result[i].second;
    }
    return res;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, l;
        cin >> n >> l;
        vector<tuple<int, int, int>> pd(n);
        for (int i = 0; i < n; i++)
        {
            cin >> get<0>(pd[i]) >> get<1>(pd[i]);
            get<2>(pd[i]) = i + 1;
            if (get<1>(pd[i]) == 0)
            {
                get<1>(pd[i]) = -1;
            }
        }
        vector<int> res = solve(pd, n, l);
        cout << "Case #" << t << ": " << res << endl;
    }
    return EXIT_SUCCESS;
}
