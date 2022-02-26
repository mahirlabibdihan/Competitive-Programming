#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Edge
{
    int begin;
    string name;
    int time;
    int nCars;
};
// Each intersection only cares about incoming edges
int main()
{
    freopen("in.txt", "r", stdin);
    int duration, nIntersections, nStreets, nCars, bonus;
    cin >> duration >> nIntersections >> nStreets >> nCars >> bonus;
    vector<vector<Edge>> adj(nIntersections);
    for (int i = 0; i < nStreets; i++)
    {
        int begin, end, time;
        string name;
        cin >> begin >> end >> name >> time;
        adj[end].push_back({begin, name, time, 0});
    }
    vector<vector<string>> path(nCars);
    map<string, int> count;
    for (int i = 0; i < nCars; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string name;
            cin >> name;
            path[i].push_back(name);
            count[name]++;
        }
    }
    freopen("out.txt", "w", stdout);
    cout << nIntersections << endl;
    for (int i = 0; i < nIntersections; i++)
    {
        int GCD = -1;
        int c = 0;
        for (Edge &e : adj[i])
        {
            e.nCars = count[e.name];
            c += (e.nCars > 0);
            if (GCD == -1)
            {
                GCD = e.nCars;
            }
            else if (e.nCars)
            {
                GCD = __gcd(GCD, e.nCars);
            }
        }
        cout << i << endl;
        cout << c << endl;
        for (Edge &e : adj[i])
        {
            e.nCars /= GCD;
            if (e.nCars > 0)
            {
                cout << e.name << " " << e.time << endl;
            }
        }
    }
}