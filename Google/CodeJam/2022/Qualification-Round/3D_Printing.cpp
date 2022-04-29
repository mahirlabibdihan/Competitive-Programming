#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int color[3][4];
        int minColor[4];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> color[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int m = INT_MAX;
            for (int j = 0; j < 3; j++)
            {
                m = min(m, color[j][i]);
            }
            minColor[i] = m;
            sum += m;
        }

        printf("Case #%d: ", t);
        int W = 1000000;
        if (sum < W)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                cout << min(minColor[i], W) << ' ';
                W -= min(minColor[i], W);
            }
        }
        cout << endl;
    }
}