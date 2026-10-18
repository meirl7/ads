#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<char> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    char c;
    cin >> c;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > c)
        {
            cout << a[i];
            return 0;
        }
    }
    cout << a[0];
}