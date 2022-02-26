// Each row and column must be of the same color
// So, the last coloring in a row or column will determine it's color
// For each operation we will have k options
// For each unique row and column we will have k options
// Corner: n=1 or m=1
// Maximum q different colors in the matrix
// Any operation will be ingored if after that all the row/column of that operation is colored again
// Why dison't we start from last operation?
#include <iostream>
#include <vector>
#include <set>
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
using namespace std;
// Sum of all q over all test case is <= 2*10^5
// That's why only O(q) is acceptable
int main()
{
    // FASTIO;
    // freopen("output.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m, k, q;
        scanf("%d%d%d%d", &n, &m, &k, &q);
        vector<int> x(q), y(q);
        // O(q) q<=2*10^5
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        set<int> xs, ys;
        int sum = 1;
        for (int i = q - 1; i >= 0; i--)
        {
            bool flag = false;
            if (!xs.count(x[i]))
            {
                xs.insert(x[i]);
                flag = true;
            }
            if (!ys.count(y[i]))
            {
                ys.insert(y[i]);
                flag = true;
            }
            if (flag)
            {
                sum = (sum * 1LL * k) % 998244353;
            }
            if (xs.size() == n || ys.size() == m)
            {
                break;
            }
        }
        printf("%d\n", sum);
    }
}