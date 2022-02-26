#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("output.txt", "w", stdout);
    int t = 1000;
    int N = 200000;
    int M = 200000;
    int K = 200000;
    int Q = 200000;
    cout << t << endl;
    while (t--)
    {
        int n = N;
        int m = M;
        int k = K;
        int q = 1;
        if (q > 0)
        {
            q = 1 + (rand() % Q);
        }
        cout << n << " " << m << " "
             << " " << k << " " << q << endl;
        for (int i = 0; i < q; i++)
        {
            int x = 1 + (rand() % n);
            int y = 1 + (rand() % m);
            cout << x << " " << y << endl;
        }
        Q -= q;
    }
}