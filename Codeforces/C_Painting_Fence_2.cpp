#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// At each step we will paint the maximum possible. Either it's in vertical or horizontal
int paint(int *A, int L, int R)
{
    if (L > R)
    {
        return 0;
    }
    cout << L << " " << R << endl;
    int count = 0;
    int l = L, r = R;
    int peak = l;
    int ones = 0;
    for (int i = l; i <= r; i++)
    {
        if (A[peak] < A[i])
        {
            peak = i;
        }
        if (A[i] == 1)
        {
            ones++;
        }
    }
    if (ones < 2 && A[peak] > R - L + 1) // When height is greater than width
    {
        count = 1 + paint(A, L, peak - 1) + paint(A, peak + 1, R);
    }
    else // No peaks
    {
        if (l == L)
        {
            count = 1;
            for (int i = l; i <= r; i++)
            {
                A[i]--;
                if (A[i] == 0)
                {
                    if (l < i)
                    {
                        count += paint(A, l, i - 1);
                    }
                    l = i + 1;
                }
            }
        }
        if (l <= r)
        {
            count += paint(A, l, r);
        }
    }
    return count;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << paint(a, 0, n - 1) << endl;
}
int main()
{
    freopen("out.txt", "r", stdin);
    FASTIO;
    int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
}