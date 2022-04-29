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
class Point
{
public:
    int x, y;
    Point()
    {
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool compX(const Point &a, const Point &b)
{
    return a.x < b.x;
}
bool compY(const Point &a, const Point &b)
{
    return a.y < b.y;
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    // vector<int> b(a);
    sort(a.begin(), a.end(), compX);
    vector<int> preSum(n), postSum(n), sum(n);
    preSum[0] = 0;
    for (int i = 1; i < n; i++)
    {
        preSum[i] = preSum[i - 1] + i * (a[i].x - a[i - 1].x);
    }
    postSum[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        postSum[i] = postSum[i + 1] + (n - i - 1) * (a[i + 1].x - a[i].x);
    }
    for (int i = 0; i < n; i++)
    {
        sum[i] = preSum[i] + postSum[i];
    }
    cout << sum << endl;
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
// 1 2 3 4
// 0 1 3 6