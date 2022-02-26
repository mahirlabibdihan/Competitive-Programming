#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<bool> visited(n + 1, false);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[a[i] - 1])
        {
            // cout << a[i] << endl;
            c++;
        }
        visited[a[i]] = true;
    }
    cout << c << endl;
}