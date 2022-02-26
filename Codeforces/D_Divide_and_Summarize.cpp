// Needs to sort the array
// Divide the array from mid
// Calculate the sum of divided array
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
using namespace std;

vector<int> a;
int64_t *st;
map<int64_t, bool> m;
int n, s;
int64_t getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}
int64_t getSum(int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return getSumUtil(0, n - 1, qs, qe, 0);
}
int64_t constructSTUtil(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = a[ss];
        return a[ss];
    }
    int mid = (ss + se) / 2;
    st[si] = constructSTUtil(ss, mid, si * 2 + 1) +
             constructSTUtil(mid + 1, se, si * 2 + 2);
    return st[si];
}
void constructST()
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (2 << x) - 1;
    st = new int64_t[max_size];
    constructSTUtil(0, n - 1, 0);
}
void DnC(int l, int r)
{
    m[getSum(l, r)] = true;
    int midValue = (a[l] + a[r]) / 2;
    if (midValue == a[r])
    {
        return;
    }
    int mid = upper_bound(a.begin() + l, a.begin() + r + 1, midValue) - a.begin();
    DnC(l, mid - 1);
    DnC(mid, r);
}
void solve()
{
    sort(a.begin(), a.end()); // O(nlogn)
    constructST();            // O(nlogn)
    DnC(0, n - 1);
    delete[] st;
}
int main()
{
    FASTIO;
    // freopen("output.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> n >> q;
        a.clear();
        m.clear();
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        solve();
        while (q--)
        {
            cin >> s;
            if (m[s] == true)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
}