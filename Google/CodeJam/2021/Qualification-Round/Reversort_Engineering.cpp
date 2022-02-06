// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Just implemented the pseudo code given in the question
// n: size of array [2<=n<=100]
// c: total cost [n-1 <= c <= (n(n+1)/2)-1]
vector<int> Reversort(int n, int c)
{
    vector<int> arr;
    if (c < n - 1 || c > (n * (n + 1) / 2) - 1)
        return arr;
    // Time complexity: O(n^2) [2<=n<=100]
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i);
    }
    // (7-1)*1
    // (7-1)*2
    //
    // 1 3 4 5 6 7 2 -> 1
    // 1 2 4 5 6 7 3 -> 6
    // 1 2 3 5 6 7 4 -> 5
    // 1 2 3 4 6 7 5 -> 4
    // 1 2 3 4 5 7 6 -> 3
    // 1 2 3 4 5 6 7 -> 3
    // 2 3 4 5 6 7 1
    //
    return arr;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr = Reversort(n, c);
        printf("Case #%d: ", t);
        if (arr.size() < n)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i : arr)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
