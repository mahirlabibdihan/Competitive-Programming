#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
typedef long long int64;
typedef unsigned long long uint64;

// First we need to remove the letters which are already common
// Then count of rest letters should divisible by k
// Then job sequencing
bool solve(string a, string b, int n, int k)
{
    map<char, int> countA, countB;
    for (int i = 0; i < n; i++)
    {
        countB[b[i]]++;
        countA[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (countA[b[i]] > 0)
        {
            countB[b[i]]--;
            countA[b[i]]--;
        }
    }
    vector<pair<char, int>> c, d;
    for (auto i : countA)
    {
        if ((i.second % k) != 0)
        {
            return false;
        }
        if (i.second > 0)
        {
            c.push_back(i);
        }
    }
    for (auto i : countB)
    {
        if ((i.second % k) != 0)
        {
            return false;
        }
        if (i.second > 0)
        {
            d.push_back(i);
        }
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    while (!d.empty())
    {
        if (d.back().first >= c.back().first)
        {
            if (d.back().second > c.back().second)
            {
                d.back().second -= c.back().second;
                c.pop_back();
            }
            else if (d.back().second == c.back().second)
            {
                c.pop_back();
                d.pop_back();
            }
            else
            {
                c.back().second -= d.back().second;
                d.pop_back();
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        if (solve(a, b, n, k))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}