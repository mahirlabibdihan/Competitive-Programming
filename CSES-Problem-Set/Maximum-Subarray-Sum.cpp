#include <iostream>
#include <vector>
using namespace std;
typedef long long int64;
int64 maxSubArraySum(vector<int> arr, int n)
{
    if (n == 0)
        return 0;
    int64 maxSum = arr[0];
    int64 sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum = arr[i] > sum + arr[i] ? arr[i] : sum + arr[i];
        maxSum = maxSum > sum ? maxSum : sum;
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    cout << maxSubArraySum(a, n) << endl;
}