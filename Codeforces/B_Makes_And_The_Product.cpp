#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int64;
int64 nCr(int n, int r)
{
    int64 s = 1, i;
    if (r > n - r)
        r = n - r;
    for (i = 1; i < r + 1; i++)
        s = (s * (n - r + i)) / i;
    return s;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int &i : a)
    {
        cin >> i;
        freq[i]++;
    }
    sort(a.begin(), a.end());
    int N = freq[a[2]];
    int R = 1 + (a[2] == a[1] ? 1 : 0) + (a[2] == a[0] ? 1 : 0);
    cout << nCr(N, R) << endl;
}