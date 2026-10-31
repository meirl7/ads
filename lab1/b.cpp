#include <iostream>

using namespace std;

#define ull unsigned long long

ull bin_pow(ull a, ull b, ull m)
{
    ull res = 1 % m;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    unsigned long long n, m, k;
    cin >> n >> m >> k;
    cout << bin_pow(n, m, k);
}