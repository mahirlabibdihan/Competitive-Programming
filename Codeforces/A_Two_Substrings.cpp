#include <bits/stdc++.h>
#define ll long long
using namespace std;

void runCase()
{
    string s;
    cin >> s;
    ll ab = s.find("AB");
    ll ba = s.find("BA", 1);
    if (ab != string ::npos and ba != string ::npos)
    {
        cout << "YES\n";
        return;
    }
    ba = s.find("BA");
    ab = s.find("AB", ba + 2);
    if (ab != string ::npos and ba != string ::npos)
    {
        cout << "YEs\n";
        return;
    }
    cout << "NO\n";
    return;
}

int32_t main()
{
#ifdef cmd
    freopen("in.txt", "r", stdin);
#endif
    // fastio;
    // ll tc; cin >> tc;
    // while(tc--) {
    runCase();
    // }
}
