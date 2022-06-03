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
    // ceil(n/2) or floor(n/2) peaks
    // Not possible for odd n
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (n % 2 == 0)
    {
        // If there are (n/2)+1 same values - Not possible
        sort(a.begin(), a.end());
        vector<int> result;
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] == a[(n / 2) + i])
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                result.push_back(a[i]);
                result.push_back(a[(n / 2) + i]);
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (result[i] == result[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        cout << result << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    //
    // 1 3 2 5 4
    // 1 3 2 6 4
    // 1 3 2 6 5
    // 1 4 2 3
    // 1 4 2 5
    // 1 4 2 6
    // 1 4 3 5
    // 1 4 3 6
    // 1 5 2
    // 1 5 3
    // 1 5 4
    // 1 6 2
    // 1 6 3
    // 1 6 4
    // 1 6 5

    // 1 2 3 4 5 6
    // 1 3 2 5 4 6
    // 1 3 2 3 3 4
    // 1 2 3 3 3 4
    // 2 3 1 3 3 4
    // 1 2 2 2 2 4
    // 1 4 2 4 1 2
    // 1 2 3 4 5 6
    // 1 3 2 5 4 6
    // 1 1 2 2 4 5
    // 1 2 1 5 2 4

    // 0 1 0 1 0 1

    // Need n/2 numbers which are greater than 2 numbers
    // And combination of this 2 numbers must be unique
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
