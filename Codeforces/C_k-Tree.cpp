#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
// int k, d;
// vector<int> dpT(101, -1), dpF(101, -1);
// int DnC(int n, bool found)
// {
//     if (n < 0)
//     {
//         return 0;
//     }
//     else if (found && dpT[n] != -1)
//     {
//         return dpT[n];
//     }
//     else if (!found && dpF[n] != -1)
//     {
//         return dpF[n];
//     }

//     int count = 0;
//     for (int i = 1; i <= min(n, k); i++)
//     {
//         if (i >= d)
//         {
//             count = (count + DnC(n - i, true)) % MOD;
//         }
//         else
//         {
//             count = (count + DnC(n - i, found)) % MOD;
//         }
//     }
//     if (found)
//     {
//         dpT[n] = count;
//     }
//     else
//     {
//         dpF[n] = count;
//     }
//     return count;
// }
int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> dpT(n + 1, 0), dpF(n + 1, 0);
    dpT[0] = 0;
    dpF[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(k, i); j++)
        {
            if (j >= d)
            {
                dpT[i] = (dpT[i] + dpT[i - j]) % MOD;
                dpT[i] = (dpT[i] + dpF[i - j]) % MOD;
            }
            else
            {
                dpT[i] = (dpT[i] + dpT[i - j]) % MOD;
                dpF[i] = (dpF[i] + dpF[i - j]) % MOD;
            }
        }
    }
    cout << dpT[n] << endl;
}