#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        int sum = 0;
        for (int &i : c)
        {
            cin >> i;
            sum += i;
        }
        printf("Case #%d: %d\n", t, sum % m);
    }
}