#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int> a, vector<int> b, int n, int m, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int count = 0;
    int i, j = 0;
    for (i = 0; i < m; i++)
    {
        for (; j < n; j++)
        {
            if (a[j] >= b[i])
            {
                if (a[j] - b[i] <= k)
                {
                    j++;
                    count++;
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (b[i] - a[j] <= k)
                {
                    j++;
                    count++;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if (j == n)
        {
            break;
        }
    }
    return count;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a)
    {
        cin >> i;
    }
    for (int &i : b)
    {
        cin >> i;
    }
    cout << solve(a, b, n, m, k) << endl;
}