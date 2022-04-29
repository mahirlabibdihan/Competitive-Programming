#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <map>
using namespace std;
template <typename T>
void print(T var1)
{
#ifndef ONLINE_JUDGE
    cout << var1 << endl;
#endif
}
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
#ifndef ONLINE_JUDGE
    cout << var1 << " ";
    print(var2...);
#endif
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    stack<pair<char, int>> bra;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' || s[i] == '(')
        {
            bra.push({s[i], i});
            m[bra.top().second] = i;
        }
        else
        {
            if (bra.empty())
            {
            }
            else if ((bra.top().first == '[' && s[i] == ']') || (bra.top().first == '(' && s[i] == ')'))
            {
                m[bra.top().second] = i;
                bra.pop();
            }
            else
            {
                while (!bra.empty())
                {
                    bra.pop();
                }
            }
        }
    }
    int maxCount = 0, minL = n, maxR = 0;
    int count = 0, l = n, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i] > i)
        {
            l = min(l, i);
            r = max(r, m[i]);
            for (int j = i; j <= m[i]; j++)
            {
                if (s[j] == '[')
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                minL = l;
                maxR = r;
            }
            i = m[i];
        }
        else
        {
            count = 0;
            l = n;
            r = 0;
        }
    }
    cout << maxCount << endl;
    for (int i = minL; i <= maxR; i++)
    {
        cout << s[i];
    }
    cerr << "DONE" << endl;
}
// [[(())]]
