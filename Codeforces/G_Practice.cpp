#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// Divide the numbers into two array into a an b size
// After first game swap last a-1 and b-1 numbers
// After second game swap last a-2 and b-2 numbers
void DnC(int l, int r, int dir, int level, vector<vector<int>> &a)
{
    if (dir == -1)
    {
        for (int i = l; i <= r; i++)
        {
            a[level].push_back(i);
        }
    }
    if (l == r)
        return;
    int m = l + (r - l) / 2;
    DnC(l, m, -1, level + 1, a);
    DnC(m + 1, r, 1, level + 1, a);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int m = ceil(log2(n));
    cout << m << endl;
    vector<vector<int>> a(m);
    DnC(1, n, 0, -1, a);
    for (auto i : a)
    {
        cout << i.size() << " ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}