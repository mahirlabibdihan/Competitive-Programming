#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i : a)
    {
        cin >> i;
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << endl;
}