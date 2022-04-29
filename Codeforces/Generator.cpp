#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("output.txt", "w", stdout);
    int n = 100000;
    cout << n << endl;
    while (n--)
    {
        cout << 1000000000LL << " ";
    }
}