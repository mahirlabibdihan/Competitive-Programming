// We can always reverse an sub array by inserting
// We need one common element already in the array
#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;
// For solution to exist,need duplicate elements
// Frequency of every elements must be even
void decode(vector<int> &result, vector<pair<int, int>> &steps, int &left)
{
    map<int, int> idx;
    int offset = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (idx.find(a[i]) != idx.end() && idx[a[i]] != -1)
        {
            reverse(a.begin() + left, a.begin() + idx[a[i]] + 1);
            // cout << "reversed" << left << " " << idx[a[i]] << " " << i << endl;
            // for (int k : a)
            // {
            //     cout << k << " ";
            // }
            // cout << endl;
            for (int j = left + 1; j < i; j++)
            {
                // a.insert(a.begin() + i + j - left, {a[j], a[j]});
                steps.push_back({offset + i + j - left, a[j]});
            }
            offset += i - left + 1;
            idx.clear();
            result.push_back(2 * (i - left));
            left = i + i - left;
            i = left - 1;
        }
        else
        {
            // cout << "Set" << i << endl;
            idx[a[i]] = i;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> result;
    vector<pair<int, int>> steps;
    int left = 0;
    decode(result, steps, left);
    if (left < a.size())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << steps.size() << endl;
        for (auto i : steps)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << result.size() << endl;
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
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
