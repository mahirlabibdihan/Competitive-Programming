#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> GetHIndexScore(vector<int> c)
{
    int n = c.size();
    vector<int> h_index(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxC = 0;
    // O(n)
    for (int i = 0; i < n; i++)
    {
        pq.push(c[i]);
        while (pq.top() < pq.size())
        {
            pq.pop();
        }
        h_index[i] = pq.size();
    }
    return h_index;
}

int main()
{
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++)
    {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++)
        {
            cin >> citations[i];
        }
        vector<int> answer = GetHIndexScore(citations);
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
