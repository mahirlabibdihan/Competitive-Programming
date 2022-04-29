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
double solve(int64 R, int64 A, int64 B)
{
    // Right circle will be zero first
    // Suppose after k turns right circle is zero at k+1
    // R +R*A
    // R/B + R*A*A/B
    // floor(1+A^(i))/(B^(i-1))
    // R*floor(1+A^(i+1))/(B^i)
    double sum = 0;
    int64 rL = R, rR = rL * A;
    for (int i = 0;; i++)
    {
        if (rL == 0)
            break;
        // cout << rL << " " << rR << endl;
        sum = sum + (rL * rL);
        sum = sum + (rR * rR);
        rL = rR / B;
        rR = rL * A;
    }
    sum = sum * acos(-1);
    return sum;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int64 R, A, B;
        cin >> R >> A >> B;
        double s = solve(R, A, B);
        // cout << "Case #" << t << ": " << s << '\n';
        printf("Case #%d: %lf\n", t, s);
    }
    return EXIT_SUCCESS;
}
