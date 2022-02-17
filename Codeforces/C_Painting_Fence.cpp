#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// At each step we will paint the maximum possible. Either it's in vertical or horizontal
vector<int> a(5000);
vector<int> visited(5000);
int *st;
int n;
int getMid(int s, int e) { return s + (e - s) / 2; }
int RMQUtil(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return min(RMQUtil(ss, mid, qs, qe, 2 * index + 1),
               RMQUtil(mid + 1, se, qs, qe, 2 * index + 2));
}
int RMQ(int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return RMQUtil(0, n - 1, qs, qe, 0);
}
int constructSTUtil(int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = a[ss];
        return a[ss];
    }
    int mid = getMid(ss, se);
    st[si] = min(constructSTUtil(ss, mid, st, si * 2 + 1),
                 constructSTUtil(mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int *constructST(int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(0, n - 1, st, 0);
    return st;
}
int paint(int L, int R, int height)
{
    if (L > R)
    {
        return 0;
    }
    if (L == R)
    {
        return 1;
    }
    int minFench = RMQ(n, L, R);
    // cout << minFench << endl;
    vector<int> pivots;
    for (int i = L; i <= R; i++)
    {
        if (a[i] == minFench)
        {
            pivots.push_back(i);
        }
    }

    int vCount = R - L + 1;
    int hCount = minFench - height;
    int p = pivots.size();
    if (pivots.front() != L)
    {
        hCount += paint(L, pivots.front() - 1, minFench);
    }
    for (int i = 1; i < p; i++)
    {
        if (pivots[i] != pivots[i - 1] + 1)
        {
            hCount += paint(pivots[i - 1] + 1, pivots[i] - 1, minFench);
        }
    }
    if (pivots.back() != R)
    {
        hCount += paint(pivots.back() + 1, R, minFench);
    }
    return min(hCount, vCount);
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    st = constructST(n);
    cout << paint(0, n - 1, 0) << endl;
}
int main()
{
    solve();
}