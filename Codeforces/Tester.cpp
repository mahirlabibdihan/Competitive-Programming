#include <iostream>
using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int t = 1;
    cout << t << endl;
    while (t--)
    {
        int n = 5000;
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}