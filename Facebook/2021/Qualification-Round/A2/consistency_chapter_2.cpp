// We will create a graph of 26 nodes and max 300 edges.
// And find the shortest path from one letter to any other letter
// Then we will find the letters which common joining point of every letter present in S
// Then we will take minimum cost of them
// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int solve(string s, vector<char> a, vector<char> b, int k)
{
    vector<vector<int>> adj(26);
    for (int i = 0; i < k; i++)
    {
        adj[a[i] - 'A'].push_back(b[i] - 'A');
    }
    vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
    for (int i = 0; i < 26; i++)
    {
        queue<int> q;
        q.push(i); // Initialize Q
        vector<bool> visited(26, false);
        visited[i] = true;
        dist[i][i] = 0;
        while (!q.empty())
        { // Process all vertices on Q
            int v = q.front();
            q.pop();
            // PreVisit(G, v); // Take appropriate action
            for (int w : adj[v])
            {
                if (!visited[w])
                {
                    visited[w] = true;
                    dist[i][w] = dist[i][v] + 1;
                    q.push(w);
                }
            }
        }
    }
    vector<int> possible;
    for (int i = 0; i < 26; i++)
    {
        for (char c : s)
        {
            if (dist[c - 'A'][i] == INT_MAX)
            {
                goto X;
            }
        }
        possible.push_back(i);
    X:;
    }
    if (possible.empty())
    {
        return -1;
    }
    int minSeconds = INT_MAX;

    for (int i : possible)
    {
        int seconds = 0;
        for (char c : s)
        {
            seconds += dist[c - 'A'][i];
        }
        minSeconds = min(minSeconds, seconds);
    }
    return minSeconds;
}
int main()
{
    freopen("consistency_chapter_2_input.txt", "r", stdin);
    freopen("consistency_chapter_2_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector<char> a(k), b(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i] >> b[i];
        }
        printf("Case #%d: %d\n", t, solve(s, a, b, k));
    }
}
// FOXEN