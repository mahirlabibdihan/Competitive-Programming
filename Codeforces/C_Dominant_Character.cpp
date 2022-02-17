#include <iostream>
using namespace std;

int solve(string s, int n)
{
    int l = -1, r = -1;
    int nA = 0, nB = 0, nC = 0;
    int lastnB = 0, lastnC = 0;
    int minLen = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            if (nA == 0) // Go to state 1
            {
                l = i;
                nA = 1;
                nB = lastnB = 0;
                nC = lastnC = 0;
            }
            else if (nA == 1)
            {
                if (nA >= nB && nA >= nC) // Stay in state 1
                {
                    minLen = min(minLen, i - l + 1);
                    l = i;
                    nA = 1;
                    nB = lastnB = 0;
                    nC = lastnC = 0;
                }
                else // Go to state 2
                {
                    nA++;
                    lastnB = nB;
                    lastnC = nC;
                }
            }
            else if (nA == 2)
            {
                if (nA > nB - lastnB && nA > nC - lastnC) // Go to state 1
                {
                    minLen = min(minLen, i - r + 1);
                    l = i;
                    nA = 1;
                    nB = lastnB = 0;
                    nC = lastnC = 0;
                }
                else if (nA >= nB && nA >= nC) // Go to state 1
                {
                    minLen = min(minLen, i - l + 1);
                    l = i;
                    nA = 1;
                    nB = lastnB = 0;
                    nC = lastnC = 0;
                }
                else // Stay in state 2
                {
                    l = r;
                    nB = lastnB = nB - lastnB;
                    nC = lastnC = nC - lastnC;
                }
            }
            r = i;
        }
        else if (nA > 0)
        {
            if (s[i] == 'b')
            {
                nB++;
            }
            else if (s[i] == 'c')
            {
                nC++;
            }
        }
    }
    return (minLen < n + 1 ? minLen : -1);
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
        if (t == 68466)
        {
            // cout << s << "-" << n << endl;
        }
        cout << solve(s, n) << endl;
    }
}