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
struct Customer
{
    int t, l, h;
    Customer()
    {
        t = 0;
    }
    bool operator<(const Customer &c)
    {
        return this->t > c.t;
    }
};
bool DnC(vector<Customer> &c, int n, int mn, int mx)
{
    if (n == 0)
    {
        return true;
    }
    // cout << n << " " << mn << " " << mx << endl;
    mn -= (c[n - 1].t - c[n].t);
    mx += (c[n - 1].t - c[n].t);
    // cout << n << " " << mn << " " << mx << endl;
    if (c[n - 1].l > mx || c[n - 1].h < mn)
    {
        return false;
    }
    mn = max(mn, c[n - 1].l);
    mx = min(mx, c[n - 1].h);
    return DnC(c, n - 1, mn, mx);
}
void solve()
{
    // Lets sort the array of customers in increasing order based on t
    // n<100
    // So we can go to O(n^2)
    // At t[i] temparature must be from l[i] to h[i]
    // Let's say temparature at t[i] is x.
    // l[i]<=x<=h[i] . We should set x in such a way that we fulfill the requirement of next customer.
    // If present time is T1 and temp x1. Next time is T2.
    // Temp at T2 can be, x1-(T2-T1)<= x2 <=x1+(T2-T1)
    // Overlapping
    // Initial temp: m1
    // Next time: m-(t[0])<= m2 <= m+(t[0]) expected l[0]<= m2 <= r[0]
    // max(m-(t[i]-t[i-1]),l[i])<= m2 <= min(m+(t[i]-t[i-1]),r[i])
    int n, m;
    cin >> n >> m;
    vector<Customer> c(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].t >> c[i].l >> c[i].h;
    }
    sort(c.begin(), c.end());
    if (DnC(c, n, m, m))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    FAST_IO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
