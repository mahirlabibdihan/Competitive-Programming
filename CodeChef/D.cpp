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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    map<int, int> m;
    for (int &i : a)
    {
        cin >> i;
        m[i]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (m[i] == 0)
        {
            break;
        }
        else if (m[i] == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
