#include <iostream>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// 2 banana + 1 apple
// x banana + y apple
void solve()
{
    int n, x;
    cin >> n >> x;
    cout << x % (n + 1) << endl;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}