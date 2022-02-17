// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;
#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);

// Graph class represents a undirected graph
// using adjacency list representation
// C++ implementation of disjoint set
#include <iostream>
using namespace std;
class DisjSet
{
    int *parent, n;

public:
    int count;
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n)
    {
        count = 0;
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Finds set of given item x
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        count++;
        parent[xset] = yset;
    }
};
// Driver code
void solve()
{
    int n;
    cin >> n;
    DisjSet g(n);
    vector<int> a(n);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int &i : a)
    {
        cin >> i;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                if (parent[i] != parent[j])
                {
                    parent[j] = i;
                }
            }
            else
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
