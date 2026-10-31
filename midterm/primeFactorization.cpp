#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++)
        if (isPrime[i])
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;

    for (int i = 2; i <= limit; i++) 
    {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

void primeFactorization(int n, const vector<int>& primes) 
{
    int temp = n;
    for (int p : primes) 
    {
        if (p * p > n)
            break;
        while (n % p == 0)
        {
            cout << p << " ";
            n /= p;
        }
    }
    if (n > 1)
        cout << n;
    cout << endl;
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int limit = (int)(sqrt(num)) + 1;
    vector<int> primes = sieve(limit);

    cout << "Prime factors of " << num << ": ";
    primeFactorization(num, primes);

    return 0;
}
