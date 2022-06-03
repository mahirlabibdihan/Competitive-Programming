#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    int l = -1;
    int sub_or = 0;
    for (int i = 0; i < n; i++)
    {
        if (x | a[i] == x)
        {
            sub_or |= a[i];
            if (sub_or == x)
            {
                count++;
            }
        }
        else
        {
            sub_or = 0;
            for (int j = i - 1; j > l; j--)
            {
                sub_or |= a[j];
                if (sub_or == x)
                {
                    count++;
                }
            }
            sub_or = 0;
            l = i;
        }
    }
    sub_or = 0;
    for (int j = n - 1; j > l + 1; j--)
    {
        sub_or |= a[j];
        if (sub_or == x)
        {
            count++;
        }
    }
    cout << count << endl;
}