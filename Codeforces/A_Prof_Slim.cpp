
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
typedef long long ll;
/**********************************************/

/************ SOLUTION *************/
void solve()
{
    // number + and number - will remain same
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        cin >> a;
        ll neg = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                neg++;
            }
        }
        for (int i = 0; i < neg; i++)
        {
            a[i] = -abs(a[i]);
        }
        for (int i = neg; i < n; i++)
        {
            a[i] = abs(a[i]);
        }
        // cout << a << endl;
        if (is_sorted(a.begin(), a.end()))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return EXIT_SUCCESS;
}
