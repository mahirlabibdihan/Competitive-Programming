// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// CJ -> X
// JC -> Y
// if x or y is positive then approach will be to avoid JC/CJ
// J?J | ?J | J? -> J -> 0
// C?C | ?C | C? -> C -> 0
// J?C -> J/C -> Y
// C?J -> J/C -> X

// If C comes after J -> add Y
// If J comes after C -> add X

// x negative -> Try to add CJ
// J?J ->
// ?J -> C -> X
// J? -> J -> 0
// C?C ->
// ?C -> C -> 0
// C? -> J -> X
// J?C -> J/C -> Y
// C?J -> J/C -> X

// y negative

// x and y negative
// J?J | ?J | J? -> C -> Y
// C?C | ?C | C? -> J -> X
// J?C -> J/C -> Y
// C?J -> J/C -> X

int getMinCost(string s, int x, int y)
{
    char lastChar = '\0';
    int minCost = 0;
    for (char c : s)
    {
        if (c != '?')
        {
            if (lastChar == 'J' && c == 'C')
            {
                minCost += y;
            }
            else if (lastChar == 'C' && c == 'J')
            {
                minCost += x;
            }
            lastChar = c;
        }
    }
    return minCost;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int x, y; // 1<= x,y <= 100
        string s; // 1<= |S| <= 1000
        cin >> x >> y >> s;
        printf("Case #%d: %d\n", t, getMinCost(s, x, y));
    }
}