#include <iostream>

using namespace std;

using ull = unsigned long long;

bool isPrime(ull n)
{
    if (n < 2)
        return false;
    
    for (ull i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ull n;
    cin >> n;
    cout << (isPrime(n) ? "YES" : "NO") << endl;
}