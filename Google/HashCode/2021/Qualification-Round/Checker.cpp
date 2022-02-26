#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Edge
{
    int begin;
    string name;
    int time;
    int nCars;
};
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
}