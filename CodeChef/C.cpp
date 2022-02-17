#include <iostream>
#include <set>
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
    int n;
    cin >> n;
    set<int> x, y;
    for (int i = 0; i < n; i++)
    {
        int X, Y;
        cin >> X >> Y;
        x.insert(X);
        y.insert(Y);
    }
    cout << x.size() + y.size() << endl;
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
