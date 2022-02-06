// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c#problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Just implemented the pseudo code given in the question
int Reversort(vector<int> arr, int n)
{
    int cost = 0; // n-1 <= cost <= (n(n+1)/2)-1 -> [1<=cost<=5049]
    // Time complexity: O(n^2) [2<=n<=100]
    for (int i = 0; i < n - 1; i++)
    {
        int j = min_element(arr.begin() + i, arr.end()) - arr.begin(); // O(n)
        cost += j - i + 1;
        reverse(arr.begin() + i, arr.begin() + j + 1); // O(n)
    }
    return cost;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        printf("Case #%d: %d\n", t, Reversort(arr, n));
    }
}
// One final note, there are solutions to this problem that run in O(NlogN) time, but they are a lot more complex. Do you want to try to find one?
// Note: The array will contain all the numbers from 1 to n.
// The final array will always be 1,2,3,4.....n
// At i-th iteration the minimum number will be 'i'
// So we need to know where will be 'i' at  i-th oteration
// May be segment tree   