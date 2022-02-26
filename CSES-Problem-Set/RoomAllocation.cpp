#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Activity
{
    int start, finish, id;
    bool operator<(const Activity &a)
    {
        return this->start < a.start;
    }
};
int greedy(vector<Activity> &works, int n, vector<int> &allocation)
{
    sort(works.begin(), works.end());
    vector<Activity> rooms;
    int count = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (!pq.empty())
        {
            int finishTime = -pq.top().first;
            int j = pq.top().second;
            if (works[i].start > finishTime)
            {
                rooms[j] = works[i];
                allocation[works[i].id] = j + 1;
                pq.pop();
                pq.push({-rooms[j].finish, j});
                continue;
            }
        }
        rooms.push_back(works[i]);
        allocation[works[i].id] = rooms.size();
        pq.push({-rooms[count].finish, count});
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<Activity> works(n);
    for (int i = 0; i < n; i++)
    {
        cin >> works[i].start >> works[i].finish;
        works[i].id = i;
    }
    vector<int> allocation(n);
    int count = greedy(works, n, allocation);
    cout << count << endl;
    for (int i : allocation)
    {
        cout << i << " ";
    }
}
