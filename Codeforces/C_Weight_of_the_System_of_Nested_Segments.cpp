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
struct Point
{
    int x, w, id;
    bool operator<(const Point &p)
    {
        return this->w < p.w;
    }
};
struct Point2
{
    int x, w, id;
    bool operator<(const Point2 &p)
    {

        return this->x < p.x;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Point> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i].x >> p[i].w;
        p[i].id = i + 1;
    }
    sort(p.begin(), p.end());

    vector<Point2> smallest;
    int64 sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        smallest.push_back({p[i].x, p[i].w, p[i].id});
        sum += p[i].w;
    }
    sort(smallest.begin(), smallest.end());
    cout << sum << endl;
    for (int i = 0; i < n; i++)
    {
        cout << smallest[i].id << " " << smallest[2 * n - i - 1].id << endl;
    }
    cout << endl;
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
