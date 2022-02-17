#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

bool dihan(vector<int> a, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        a[i] &= 1;
        if (!st.empty() && st.top() == a[i])
        {
            st.pop();
        }
        else
        {
            st.push(a[i]);
        }
    }
    return st.size() < 2;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (dihan(a, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}