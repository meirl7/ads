#include <iostream>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a %= b;
            continue;
        }
        b %= a;
    }
    return a + b;
}

int main()
{
    cout << gcd(1000000007, 1000000009) << endl; // prints 1
    return 0;
}