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
bool cmp(int64 a, int64 b)
{
    return a >= b;
}
void solve()
{
    // Spreading at first second is not possible
    // 1 at first second
    // At most 2 at rest of the seconds
    // Injection is possible at each second
    // Spreading depends if healthy sibling exists
    // Max second = n
    // Min second = 1+(n/2)
    // 1+(n/2) <= result <= n
    // All i are siblings if p[i] are equal
    // Group the i's with same p[i]
    // Inject root at last
    // Always try to inject such that it spreads
    int64 n;
    cin >> n;
    vector<int64> p(n + 1);
    for (int64 i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<int64> adj(n + 1, 0);
    adj[0]++;
    for (int64 i = 2; i <= n; i++)
    {
        adj[p[i]]++;
    }
    // cout << adj[n] << endl;
    sort(adj.begin(), adj.end(), cmp);
    int64 inject = 0, spread = 0;
    for (int64 i = 0; i <= n; i++)
    {
        if (adj[i] > 1)
        {
            inject += (adj[i] / 2);
            spread += adj[i] - (adj[i] / 2);
        }
        else if (adj[i] == 1)
        {
            inject++;
        }
        else
        {
            break;
        }
    }
    int64 c = inject;
    if (spread - inject + 1 > 0)
    {
        int64 rem = (spread - inject + 1);
        for (int64 i = 0; i <= n; i++)
        {
            if (rem > 1)
            {
                if (adj[i] > 1 && (adj[i] % 2) == 1)
                {
                    rem -= 2;
                    c++;
                }
                else if (adj[i] <= 1)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        if (rem > 0)
        {
            c += rem;
        }
        else
        {
            c++;
        }
    }
    cout << c << endl;
}
int main()
{
    FAST_IO;
    int64 T = 1;
    cin >> T;
    for (int64 t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
