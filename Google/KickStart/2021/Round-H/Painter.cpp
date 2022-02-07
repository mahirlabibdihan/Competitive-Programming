// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88
#include <iostream>
using namespace std;
/*
    Red + Yellow = Orange
    Red + Blue = Purple
    Yellow + Blue = Green
    Red + Yellow + Blue = Gray

    U = Uncolored = 1
    R = Red = 3
    Y = Yellow = 4
    B = Blue = 5
    O = Orange = 12
    P = Purple = 15
    G = Green = 20
    A = Gray = 60
*/
int solve(string s, int n)
{
    // R: 3
    // 3,12,15,60
    // R,O,P,A -> Red
    // 4,12,20,60
    // Y,O,G,A -> Yellow
    // 5,15,20,60
    // B,P,G,A -> Blue

    // Red
    int count = 0;
    int i, j;
    for (j = 0, i = -1; j < n; j++)
    {
        if (s[j] == 'R' || s[j] == 'O' || s[j] == 'P' || s[j] == 'A')
        {
            if (i == -1)
            {
                i = j;
            }
        }
        else
        {
            if (i != -1)
            {
                count++;
                i = -1;
            }
        }
    }
    if (i != -1)
    {
        count++;
    }
    // cout << count << endl;
    for (j = 0, i = -1; j < n; j++)
    {
        if (s[j] == 'Y' || s[j] == 'O' || s[j] == 'G' || s[j] == 'A')
        {
            if (i == -1)
            {
                i = j;
            }
        }
        else
        {
            if (i != -1)
            {
                count++;
                i = -1;
            }
        }
    }
    if (i != -1)
    {
        count++;
    }
    // cout << count << endl;
    for (j = 0, i = -1; j < n; j++)
    {
        if (s[j] == 'B' || s[j] == 'P' || s[j] == 'G' || s[j] == 'A')
        {
            if (i == -1)
            {
                i = j;
            }
        }
        else
        {
            if (i != -1)
            {
                count++;
                i = -1;
            }
        }
    }
    if (i != -1)
    {
        count++;
    }
    return count;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        printf("Case #%d: %d\n", t, solve(s, n));
    }
}