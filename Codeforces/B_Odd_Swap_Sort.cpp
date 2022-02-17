

#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// Let's think a is an odd number. It's in l index in original array.
// And in r index in the sorted array.
// So all the elements from l+1 to r must be even to sort the array.

bool cmp(const int &a, const int &b)
{
    return (((a + b) % 2) != 0) && a < b;
}
void sort(int x[], int n)
{
    int i, j;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
            if (x[i] > x[i + 1])
            {
                int k = x[i];
                x[i] = x[i + 1];
                x[i + 1] = k;
            }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), odd, even;
    for (int &i : a)
    {
        cin >> i;
        if (i % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }
    if (is_sorted(odd.begin(), odd.end()) && is_sorted(even.begin(), even.end()))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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
