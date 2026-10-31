#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a + b;
}

int main()
{
    ull a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}