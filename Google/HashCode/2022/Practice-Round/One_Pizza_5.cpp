// https://codingcompetitions.withgoogle.com/hashcode/round/00000000008f5ca9/00000000008f6f33
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
using namespace std;
// Points
// A - 2
// B - 5
// C - 5
// D - 1708
// E - 2025
vector<string> solve(vector<vector<string>> likes, vector<vector<string>> dislikes)
{
    int n = likes.size();
    vector<bool> removed(n, false);
    map<string, int> degree;
    map<string, bool> taken;
    map<string, pair<vector<int>, vector<int>>> ing;
    for (int i = 0; i < n; i++)
    {
        for (string s : likes[i])
        {
            ing[s].first.push_back(i);
        }
        for (string s : dislikes[i])
        {
            ing[s].second.push_back(i);
            degree[s]++;
        }
    }
    vector<string> all;
    for (auto i : ing)
    {
        all.push_back(i.first);
    }

    vector<string> result;
    while (true)
    {
        string minS;
        int minDegree = INT_MAX;
        for (auto i : all)
        {
            if (!taken[i])
            {
                if (degree[i] < minDegree)
                {
                    minDegree = degree[i];
                    minS = i;
                }
            }
        }
        if (minS.empty())
        {
            break;
        }
        for (int i : ing[minS].second)
        {
            if (!removed[i])
            {
                for (string s : dislikes[i])
                {
                    degree[s]--;
                }
                removed[i] = true;
            }
        }
        result.push_back(minS);
        taken[minS] = true;
    }
    return result;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int nClient;
    cin >> nClient;
    vector<vector<string>> likes(nClient), dislikes(nClient);
    for (int i = 0; i < nClient; i++)
    {
        int nLikes, nDislikes;
        cin >> nLikes;
        for (int j = 0; j < nLikes; j++)
        {
            string s;
            cin >> s;
            likes[i].push_back(s);
        }
        cin >> nDislikes;
        for (int j = 0; j < nDislikes; j++)
        {
            string s;
            cin >> s;
            dislikes[i].push_back(s);
        }
    }
    vector<string> result = solve(likes, dislikes);
    freopen("output2.txt", "w", stdout);
    cout << result.size() << " ";
    for (string s : result)
    {
        cout << s << " ";
    }
}