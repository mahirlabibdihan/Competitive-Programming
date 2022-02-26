#include <iostream>
using namespace std;

int merge(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    int aLastDigit = a % 10;
    int bLastDigit = b % 10;
    if (aLastDigit > bLastDigit)
    {
        return 10 * merge(a / 10, b) + aLastDigit;
    }
    else
    {
        return 10 * merge(a, b / 10) + bLastDigit;
    }
}

int main()
{
    cout << merge(1245, 36) << endl;
}