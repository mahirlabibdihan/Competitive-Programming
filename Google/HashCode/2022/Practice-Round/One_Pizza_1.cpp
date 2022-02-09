// https://codingcompetitions.withgoogle.com/hashcode/round/00000000008f5ca9/00000000008f6f33
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
// Points
// A - 2
// B - 5
// C - 5
// D - 1708
// E - 2025
vector<vector<int>> adj(100000);
int n;
vector<int> optimize(vector<bool> visited, vector<int> degree, int count, int pos)
{
    // cout << ".";
    // cout << pos << endl;
    // cout << "PASS" << endl;
    if (pos != -1)
    {
        visited[pos] = true;
        count++;
        for (int i : adj[pos])
        {
            if (!visited[i])
            {
                visited[i] = true;
                count++;
                for (int j : adj[i])
                {
                    if (!visited[j])
                    {
                        degree[j]--;
                    }
                }
            }
        }
    }
    // cout << "PASS" << endl;
    int minDegree = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (minDegree == -1)
            {
                minDegree = i;
            }
            else if (degree[minDegree] > degree[i])
            {
                minDegree = i;
            }
        }
    }
    // cout << "PASS" << endl;
    vector<int> result;
    if (minDegree != -1)
    {

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && degree[i] == degree[minDegree])
            {
                vector<int> temp = optimize(visited, degree, count, i);
                if (temp.size() > result.size())
                {
                    result = temp;
                }
            }
        }
    }
    if (pos != -1)
        result.push_back(pos);
    cout << result.size() << endl;
    return result;
}
vector<string> solve(vector<vector<string>> likes, vector<vector<string>> dislikes)
{
    n = likes.size();
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
        }
    }
    vector<int> degree(n, 0);
    vector<bool> visited(n, false);
    int count = 0;
    for (auto i : ing)
    {
        for (int j : i.second.first)
        {
            for (int k : i.second.second)
            {
                adj[j].push_back(k);
                adj[k].push_back(j);
                degree[j]++;
                degree[k]++;
            }
        }
    }

    vector<string> all;
    for (auto i : ing)
    {
        all.push_back(i.first);
    }

    vector<int> result = optimize(visited, degree, count, -1);
    // cout << result.size() << endl;
    map<string, bool> isDislike;
    for (int i : result)
    {
        cout << i << " ";
        for (string s : dislikes[i])
        {
            isDislike[s] = true;
        }
    }
    // cout << "DONE" << endl;
    vector<string> ingredients;
    for (string s : all)
    {
        if (!isDislike[s])
        {
            ingredients.push_back(s);
        }
    }
    // cout << "DONE" << endl;
    return ingredients;
}
int main()
{
    freopen("input2.txt", "r", stdin);
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