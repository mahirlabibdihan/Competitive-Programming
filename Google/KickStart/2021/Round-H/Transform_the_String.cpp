// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461
// Bruteforce - 2.6*10^6
#include <iostream>
using namespace std;

int minDist(char a, char b)
{
    char c = min(a, b);
    char d = max(a, b);
    return min(d - c, (c - 'a') + ('z' - d) + 1);
}
int solve(string s, string f)
{
    int cost = 0;
    for (char i : s)
    {
        int minCost = 25;
        for (char j : f)
        {
            minCost = min(minCost, minDist(i, j));
        }
        cost += minCost;
    }
    return cost;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s, f;
        cin >> s >> f;
        printf("Case #%d: %d\n", t, solve(s, f));
    }
}