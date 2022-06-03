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
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (T &i : a)
    {
        cin >> i;
    }
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (T &i : a)
    {
        cout << i << " ";
    }
    return out;
}
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

typedef long long int64;
typedef unsigned long long uint64;
/**********************************************/

/************ SOLUTION *************/
bool checkBlock(string s)
{
    map<char, int> count;
    char last = '\0';
    for (char c : s)
    {
        count[c]++;
        if (count[c] > 1 && last != c)
        {
            return false;
        }
        last = c;
    }
    return true;
}
bool inputValidation(vector<string> a)
{
    for (string s : a)
    {
        if (!checkBlock(s))
        {
            return false;
        }
    }
    return true;
}
void findMid(map<char, vector<int>> &midIdx, vector<string> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = a[i].length();
        char last = '\0';
        for (int j = 1; j < m - 1; j++)
        {
            if (a[i][j] != a[i][0] && a[i][j] != a[i][m - 1])
            {
                if (a[i][j] != last)
                {
                    midIdx[a[i][j]].push_back(i);
                }
            }
            last = a[i][j];
        }
    }
}
string solve(vector<string> a, int n)
{
    // ...AA AA...
    // First checkBlock each block for validity
    if (!inputValidation(a))
    {
        return "IMPOSSIBLE";
    }
    map<char, vector<int>> startIdx, lastIdx, idx, midIdx;
    for (int i = 0; i < n; i++)
    {
        if (a[i].front() == a[i].back())
        {
            idx[a[i].front()].push_back(i);
        }
        else
        {
            startIdx[a[i].front()].push_back(i);
            lastIdx[a[i].back()].push_back(i);
        }
    }
    findMid(midIdx, a, n);

    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (lastIdx[c].size() > 1)
        {
            return "IMPOSSIBLE";
        }
        if (startIdx[c].size() > 1)
        {
            return "IMPOSSIBLE";
        }
        if (midIdx[c].size() > 1)
        {
            return "IMPOSSIBLE";
        }
        if (idx[c].size() == n)
        {
            string result;
            for (string s : a)
            {
                result += s;
            }
            return result;
        }
    }
    char start = '\0';
    char end = '\0';
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (!lastIdx[c].empty() && startIdx[c].empty())
        {
            if (end == '\0')
                end = c; // If idx exist, end will be idx
        }
        if (!startIdx[c].empty() && lastIdx[c].empty())
        {
            if (start == '\0')
                start = c; // If idx exist, start will be idx
        }
    }
    if (start == '\0' || end == '\0')
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (!idx[c].empty() && startIdx[c].empty() && lastIdx[c].empty())
            {
                if (start == '\0')
                {
                    start = c; // If idx exist, start will be idx
                }
                else if (end == '\0')
                {
                    end = c; // If idx exist, end will be idx
                }
                else
                {
                    break;
                }
            }
        }
        if (start == '\0' || end == '\0')
        {
            return "IMPOSSIBLE";
        }
    }
    int c = 0;
    string startStr, lastStr;
    vector<bool> visited(n, false);

    while (!idx[start].empty())
    {
        startStr += a[idx[start].back()];
        visited[idx[start].back()] = true;
        idx[start].pop_back();
        c++;
    }
    if (!startIdx[start].empty())
    {
        startStr += a[startIdx[start].front()];
        visited[startIdx[start].front()] = true;
        startIdx[start].pop_back();
        c++;
    }
    if (!lastIdx[end].empty() && !visited[lastIdx[end].front()])
    {
        lastStr += a[lastIdx[end].front()];
        visited[lastIdx[end].front()] = true;
        lastIdx[end].pop_back();
        c++;
    }
    while (!idx[end].empty())
    {
        lastStr += a[idx[end].back()];
        visited[idx[end].back()] = true;
        idx[end].pop_back();
        c++;
    }
    char last = startStr.back();
    while (c < n)
    {
        if (!idx[last].empty())
        {
            if (!visited[idx[last].back()])
            {
                startStr += a[idx[last].back()];
                visited[idx[last].back()] = true;
                c++;
            }
            idx[last].pop_back();
        }
        else if (!startIdx[last].empty())
        {
            if (!visited[startIdx[last].back()])
            {
                startStr += a[startIdx[last].back()];
                visited[startIdx[last].back()] = true;
                c++;
            }
            startIdx[last].pop_back();
            last = startStr.back();
        }
        else
        {
            break;
        }
    }
    last = lastStr.front();
    while (c < n)
    {
        if (!idx[last].empty())
        {
            if (!visited[idx[last].back()])
            {
                lastStr = a[idx[last].back()] + lastStr;
                visited[idx[last].back()] = true;
                c++;
            }
            idx[last].pop_back();
        }
        else if (!lastIdx[last].empty())
        {
            if (!visited[lastIdx[last].back()])
            {
                lastStr = a[lastIdx[last].back()] + lastStr;
                visited[lastIdx[last].back()] = true;
                c++;
            }
            lastIdx[last].pop_back();
            last = lastStr.front();
        }
        else
        {
            break;
        }
    }
    string result = startStr + lastStr;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (!startIdx[c].empty())
        {
            if (visited[startIdx[c].back()])
                startIdx[c].pop_back();
            else
                return "IMPOSSIBLE";
        }
        if (!lastIdx[c].empty())
        {
            if (visited[lastIdx[c].back()])
                lastIdx[c].pop_back();
            else
                return "IMPOSSIBLE";
        }
        while (!idx[c].empty())
        {
            if (!visited[idx[c].back()])
            {
                result += a[idx[c].back()];
            }
            else
            {
                return "IMPOSSIBLE";
            }
            idx[c].pop_back();
        }
    }
    if (!checkBlock(result))
        return "IMPOSSIBLE";
    return result;
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "Case #" << t << ": " << solve(a, n) << endl;
    }
    return EXIT_SUCCESS;
}
