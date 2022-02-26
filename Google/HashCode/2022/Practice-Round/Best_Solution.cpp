// Mahir Labib Dihan
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
// D - 1728
// E - 2069
int calculateRemovedEdges(vector<vector<int>> adj, vector<bool> visited, int i)
{
    int count = 0;
    for (int j : adj[i])
    {
        if (!visited[j])
        {
            visited[j] = true;
            for (int k : adj[j])
            {
                if (!visited[k])
                {
                    count++;
                }
            }
        }
    }
    return count;
}
vector<string> solve(vector<vector<string>> likes, vector<vector<string>> dislikes)
{
    int n = likes.size();
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
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    vector<bool> visited(n, false);
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
    vector<int> result;
    int count = 0;
    map<string, bool> isDislike;
    while (count < n)
    {
        int minDegree = -1;
        int maxEdgeCount = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << degree[i] << " ";
            if (!visited[i])
            {
                if (minDegree == -1)
                {
                    minDegree = i;
                    maxEdgeCount = calculateRemovedEdges(adj, visited, i);
                }
                else if (degree[minDegree] > degree[i])
                {
                    minDegree = i;
                    maxEdgeCount = calculateRemovedEdges(adj, visited, i);
                }
                else if (degree[minDegree] == degree[i])
                {
                    int edgeCount = calculateRemovedEdges(adj, visited, i);
                    if (edgeCount > maxEdgeCount)
                    {
                        maxEdgeCount = edgeCount;
                        minDegree = i;
                    }
                }
            }
        }
        // When there are multiple options for mindegree we are not considering any optimal way
        // There is a space of optimization
        // cout << count << endl;
        visited[minDegree] = true;
        count++;
        // result.push_back(minDegree);
        for (string s : dislikes[minDegree])
        {
            isDislike[s] = true;
        }
        for (int i : adj[minDegree])
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
    cout << result.size() << endl;
    vector<string> all;
    for (auto i : ing)
    {
        all.push_back(i.first);
    }
    vector<string> ingredients;
    for (string s : all)
    {
        if (!isDislike[s])
        {
            ingredients.push_back(s);
        }
    }
    return ingredients;
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
    freopen("out.txt", "w", stdout);
    cout << result.size() << " ";
    for (string s : result)
    {
        cout << s << " ";
    }
}