#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int n, int source, vector<int64_t> &dist, vector<int> &parent)
{
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int64_t, int>> pq;
    dist[source] = 0;
    parent[source] = -1;
    pq.push({-dist[source], source});

    // Initialize heap array
    // O(ElogV)
    for (int i = 0; i < n; i++)
    { // Now, get distances
        pair<int64_t, int> temp;
        int64_t u, w;
        do
        {
            if (pq.empty())
            {
                // Nothing to remove
                return;
            }
            temp = pq.top();
            u = temp.second;
            w = -temp.first;
            pq.pop(); // O(logV)
        } while (visited[u]);
        visited[u] = true;

        for (pair<int, int> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            int w = i.second;

            // RELAX
            if (!visited[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;  // Update distance
                parent[v] = u;          // Update who it came from
                pq.push({-dist[v], v}); // Insert new distance in heap // O(logV)
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int s, d;
    // cin >> s >> d;
    vector<int64_t> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);

    // Task-1
    dijkstra(adj, n, 1, dist, parent);

    // // Task-2
    // if (!bellmanFord(adj, n, s, dist, parent))
    // {
    //     cerr << "The graph contains a negative cycle" << endl;
    //     return EXIT_FAILURE;
    // }
    // cout << "The graph does not contain a negative cycle" << endl;
    //

    // if (parent[d] == -1)
    // {
    //     cerr << "Destination not reachable" << endl;
    //     return EXIT_FAILURE;
    // }
    // cout << "Shortest path cost: " << dist[d] << endl;
    // printPath(parent[d], parent);
    // cout << d << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return EXIT_SUCCESS;
}
