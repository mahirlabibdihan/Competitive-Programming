#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> r, int nR, vector<int> g, int nG, vector<int> b, int nB)
{
    int dp[nR + 1][nG + 1][nB + 1] = {};
    for (int iR = 0; iR <= nR; iR++)
    {
        for (int iG = 0; iG <= nG; iG++)
        {
            for (int iB = 0; iB <= nB; iB++)
            {
                if (iG > 0 && iB > 0)
                {
                    dp[iR][iG][iB] = max(dp[iR][iG][iB], g[iG - 1] * b[iB - 1] + dp[iR][iG - 1][iB - 1]);
                }
                if (iR > 0 && iB > 0)
                {
                    dp[iR][iG][iB] = max(dp[iR][iG][iB], r[iR - 1] * b[iB - 1] + dp[iR - 1][iG][iB - 1]);
                }
                if (iR > 0 && iG > 0)
                {
                    dp[iR][iG][iB] = max(dp[iR][iG][iB], r[iR - 1] * g[iG - 1] + dp[iR - 1][iG - 1][iB]);
                }
            }
        }
    }
    return dp[nR][nG][nB];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int nR, nG, nB;
    cin >> nR >> nG >> nB;

    vector<int> r(nR), g(nG), b(nB);

    for (int &i : r)
        cin >> i;
    for (int &i : g)
        cin >> i;
    for (int &i : b)
        cin >> i;

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    cout << solve(r, nR, g, nG, b, nB);
}