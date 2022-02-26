#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int64;
int countAvengers(int l, int r)
{
    int low = lower_bound(a.begin(), a.end(), l) - a.begin();
    int high = upper_bound(a.begin(), a.end(), r) - a.begin();
    return high - low;
}