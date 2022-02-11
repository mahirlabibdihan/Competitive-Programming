// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;
/*
OXOX0
X.X.X
OXOX0
X.X.X
OXOXO
*/
void solve(vector<string> s, int n)
{
    int minMoves = INT_MAX;
    map<int, vector<int>> cC, rC;
    int i, j;

    // Counting rows
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (j = 0; j < n; j++)
        {
            if (s[i][j] == 'O')
            {
                break;
            }
            else if (s[i][j] == '.')
            {
                count++;
            }
        }
        if (j == n)
        {
            minMoves = min(minMoves, count);
            rC[count].push_back(i);
        }
    }

    // Counting columns
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (j = 0; j < n; j++)
        {
            if (s[j][i] == 'O')
            {
                break;
            }
            else if (s[j][i] == '.')
            {
                count++;
            }
        }
        if (j == n)
        {
            minMoves = min(minMoves, count);
            cC[count].push_back(i);
        }
    }
    if (minMoves == INT_MAX)
    {
        printf("Impossible\n");
    }
    else if (minMoves == 1)
    {
        // Counting distinct one '.'
        int count = rC[1].size() + cC[1].size();
        for (int i : rC[1])
        {
            for (int j : cC[1])
            {
                if (s[i][j] == '.')
                {
                    count--;
                }
            }
        }
        printf("%d %d\n", minMoves, count);
    }
    else
    {
        printf("%d %d\n", minMoves, rC[minMoves].size() + cC[minMoves].size());
    }
}
int main()
{
    freopen("xs_and_os_input.txt", "r", stdin);
    freopen("xs_and_os_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; // 2<= n <= 50
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        printf("Case #%d: ", t);
        solve(s, n);
    }
}
// FOXEN