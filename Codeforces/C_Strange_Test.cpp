#include <iostream>
#include <climits>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 1000000
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
// 1. b-a
// 2. (Minimum possible move to make a|b = b)+1
// b<(a|b)<1048567

int DnC(int a, int b)
{
    int i, j;
    int count = MAX;

    int idx = -1; // Last bit which conflicts with b
    for (i = 1, j = 0; i <= a; i <<= 1, j++)
    {
        if ((b | i) != b)
        {
            if ((a | i) == a)
            {
                idx = i;
            }
        }
    }
    int newA = a;
    for (i = 1, j = 0; i <= idx; i <<= 1, j++)
    {
        if ((newA | i) == newA)
        {
            newA = newA ^ i;
        }
    }

    for (i = idx << 1; i <= b; i <<= 1)
    {
        if ((b | i) == b)
        {
            if ((newA | i) != newA)
            {
                count = (newA | i) - a;
                break;
            }
            else
            {
                newA = newA ^ i;
            }
        }
    }
    return count;
}
int solve(int a, int b)
{
    int minMove = b - a;
    int mask;
    for (mask = 1; mask <= b; mask <<= 1)
        ;
    for (int i = b; i < mask; i++)
    {
        if ((a | i) == i)
        {
            minMove = min(minMove, i - b);
        }
        else
        {
            minMove = min(minMove, i - b + DnC(a, i));
        }
    }
    return minMove;
}
int main()
{
    FASTIO;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int a, b;
        cin >> a >> b;
        cout << min(b - a, int(solve(a, b)) + 1) << endl;
    }
}