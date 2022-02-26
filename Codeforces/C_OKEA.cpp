#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0 || k == 1)
        {
            cout << "YES" << endl;
            int odd = 1, even = 2;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (i % 2 == 0)
                    {
                        cout << odd << " ";
                        odd += 2;
                    }
                    else
                    {
                        cout << even << " ";
                        even += 2;
                    }
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}