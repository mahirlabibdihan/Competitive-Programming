/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <bits/stdc++.h>
using namespace std;

/************* TEMPLATE *************/
#define FAST_IO ios::sync_with_stdio(0), cin.tie(nullptr);
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (T &i : a)
    {
        cin >> i;
    }
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (T &i : a)
    {
        cout << i << " ";
    }
    return out;
}
template <typename T>
void print(T var1)
{
#ifndef ONLINE_JUDGE
    cout << var1 << endl;
#endif
}
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
#ifndef ONLINE_JUDGE
    cout << var1 << " ";
    print(var2...);
#endif
}

typedef long long int64;
typedef unsigned long long uint64;
/**********************************************/

/************ SOLUTION *************/
void solve()
{
    // -2 -1 0 1 2
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Product > 1
    // First need to obtain a sub array with no zero
    // Then need to choose even number of negative numbers
    // Two consecutive zero
    map<int, int> count;
    int maxPro = 0;
    int l = n, r = 0;
    int lastZero = -1;
    int firstNeg = -1, lastNeg = -1;
    int twoBefFirst = 0, twoAftLast = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if ((count[-2] + count[-1]) % 2 == 0)
            {
                if (count[-2] + count[2] >= maxPro)
                {
                    l = lastZero + 1;
                    r = i - 1;
                    maxPro = count[-2] + count[2];
                }
            }
            else
            {
                int pro = 0;
                if (twoBefFirst + (a[firstNeg] == -2 ? 1 : 0) < twoAftLast + (a[lastNeg] == -2 ? 1 : 0))
                {
                    pro = count[-2] + count[2] - twoBefFirst - (a[firstNeg] == -2 ? 1 : 0);
                    if (pro >= maxPro)
                    {
                        l = firstNeg + 1;
                        r = i - 1;
                        maxPro = pro;
                    }
                }
                else
                {
                    pro = count[-2] + count[2] - twoAftLast - (a[lastNeg] == -2 ? 1 : 0);
                    if (pro >= maxPro)
                    {
                        l = lastZero + 1;
                        r = lastNeg - 1;
                        maxPro = pro;
                    }
                }
            }
            count.clear();
            firstNeg = -1, lastNeg = -1;
            twoBefFirst = 0, twoAftLast = 0;
            lastZero = i;
        }
        else
        {
            count[a[i]]++;
            if (a[i] < 0)
            {
                if (count[-2] + count[-1] == 1)
                {
                    firstNeg = i;
                }
                lastNeg = i;
                twoAftLast = 0;
            }
            else
            {
                if (a[i] == 2)
                {
                    if (firstNeg == -1)
                    {
                        twoBefFirst++;
                    }
                    else if (lastNeg != -1)
                    {
                        twoAftLast++;
                    }
                }
            }
        }
    }
    // Tail check
    {
        int i = n;
        if ((count[-2] + count[-1]) % 2 == 0)
        {
            if (count[-2] + count[2] >= maxPro)
            {
                l = lastZero + 1;
                r = i - 1;
                maxPro = count[-2] + count[2];
            }
        }
        else
        {
            int pro = 0;
            if (twoBefFirst + (a[firstNeg] == -2 ? 1 : 0) < twoAftLast + (a[lastNeg] == -2 ? 1 : 0))
            {
                pro = count[-2] + count[2] - twoBefFirst - (a[firstNeg] == -2 ? 1 : 0);
                if (pro >= maxPro)
                {
                    l = firstNeg + 1;
                    r = i - 1;
                    maxPro = pro;
                }
            }
            else
            {
                pro = count[-2] + count[2] - twoAftLast - (a[lastNeg] == -2 ? 1 : 0);
                if (pro >= maxPro)
                {
                    l = lastZero + 1;
                    r = lastNeg - 1;
                    maxPro = pro;
                }
            }
        }
    }
    if (maxPro == 0)
    {
        cout << n << " " << 0 << endl;
    }
    else
    {
        cout << l << " " << n - 1 - r << endl;
    }
}
int main()
{
    FAST_IO;
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        solve();
    }
    return EXIT_SUCCESS;
}
