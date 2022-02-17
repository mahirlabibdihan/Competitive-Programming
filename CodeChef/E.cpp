#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// 1 2 2 3 3 3
// 0 0 1 1 1 2
//
// If all the numbers are greater than 0 than YES
// If not if any number exist on time than NO

// 3210
// 1 1 2 4 8 16 32 64
// 0 0 1 2 3 4

// If we can build the first building in n operations
// We can build more m-n buildings
void solve()
{
    int64 x, m;
    cin >> x >> m;
    int64 i, sum = 1;
    for (i = 0; sum < x; i++)
    {
        sum += (1LL << i);
    }
    if (m > i)
        cout << m - i << endl;
    else
        cout << 0 << endl;
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
