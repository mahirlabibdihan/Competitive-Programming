#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int64;
vector<int> a;
int n, k, A, B;
int countAvengers(int l, int r)
{
    int low = lower_bound(a.begin(), a.end(), l) - a.begin();
    int high = upper_bound(a.begin(), a.end(), r) - a.begin();
    return high - low;
}
// We can burn a base or divide it
int64 DnC(int l, int r)
{
    // cout << l << " " << r << endl;
    int64 count = countAvengers(l, r);
    // cout << count << endl;
    if (l == r)
    {
        if (count > 0)
        {
            return B * count;
        }
        else
        {
            // cout << "No avenger" << endl;
            return A;
        }
    }
    else
    {
        if (count > 0)
        {
            int mid = (l + r) / 2;
            return min(count * B * (r - l + 1), DnC(l, mid) + DnC(mid + 1, r));
        }
        else
        {
            // cout << "No avenger" << endl;
            return A;
        }
    }
}
int main()
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cout << DnC(1, 1 << n) << endl;
}