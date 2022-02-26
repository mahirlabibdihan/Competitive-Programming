// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    int curr = a[0];
    int rem = a[0] - 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (curr > a[i])
        {
            rem--;
        }
        else if (curr < a[i])
        {
            if (rem)
            {
                rem = a[i] - 1 - (curr - rem);
                curr = a[i];
            }
            else
            {
                count++;
                rem = a[i] - 1 - (curr - rem);
                curr = a[i];
            }
        }
    }
    cout << count << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}