#include <iostream>
using namespace std;

string s1, s2;
int n, m;
bool isEqu(int s1L, int s1R, int s2L, int s2R)
{
    if ((s1R - s1L) % 2 == 0)
    {
        // cout << "ERROR-ODD-SEGMENT" << s1R << "-" << s1L << "-" << n << "-" << m << endl;
        for (int i = s1L, j = s2L; i <= s1R; i++, j++)
        {
            if (s1[i] != s2[j])
            {
                return false;
            }
        }
        return true;
    }
    int s1M = (s1L + s1R) / 2;
    int s2M = (s2L + s2R) / 2;
    if (isEqu(s1L, s1M, s2L, s2M) && isEqu(s1M + 1, s1R, s2M + 1, s2R))
    {
        return true;
    }
    if (isEqu(s1L, s1M, s2M + 1, s2R) && isEqu(s1M + 1, s1R, s2L, s2M))
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    if (isEqu(0, n - 1, 0, m - 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}