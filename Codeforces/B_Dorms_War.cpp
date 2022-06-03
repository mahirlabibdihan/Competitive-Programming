/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <bits/stdc++.h>
using namespace std;

/************* TEMPLATE *************/
#define FAST_IO ios::sync_with_stdio(0), cin.tie(nullptr);
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, bool> isSpecial;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            char c;
            cin >> c;
            isSpecial[c] = true;
        }
        int lastIdx = 0;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (isSpecial[s[i]])
            {
                mx = max(mx, i - lastIdx);
                lastIdx = i;
            }
        }
        cout << mx << endl;
    }
    return EXIT_SUCCESS;
}
