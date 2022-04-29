#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int r, c;
        cin >> r >> c;
        printf("Case #%d:\n", t);
        for (int i = 0; i <= 2 * r; i++)
        {
            for (int j = 0; j <= 2 * c; j++)
            {
                if (i + j < 2)
                {
                    cout << '.';
                }
                else if (i % 2)
                {
                    if (j % 2)
                    {
                        cout << '.';
                    }
                    else
                    {
                        cout << '|';
                    }
                }
                else
                {
                    if (j % 2)
                    {
                        cout << '-';
                    }
                    else
                    {
                        cout << '+';
                    }
                }
            }
            cout << '\n';
        }
    }
}