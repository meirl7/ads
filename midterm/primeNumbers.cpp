#include <iostream>
#include <vector>

using namespace std;

vector<bool> primes(int n)
{
	vector<bool> arr(n + 1, true);

	for (int i = 2; i * i <= n; i++)
		if (arr[i])
			for (int j = i * i; j <= n; j += i)
				arr[j] = false;
	return arr;
}

int main() 
{
    int n;
    cin >> n;

    vector<bool> p = primes(n);
    for (int i = 2; i <= n; i++) 
        if (p[i]) 
            cout << i << " ";
    cout << endl;
    return 0;
}