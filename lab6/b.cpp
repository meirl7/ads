#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    vector<int> b(m);

    for (int i = 0; i < m; i++) 
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> result;
    int i = 0;
    int j = 0;

    while (i < n && j < m) 
    {
        if (a[i] == b[j]) 
        {
            result.push_back(a[i]);
            i++;
            j++;
        } 
        else if (a[i] < b[j]) 
        {
            i++;
        } 
        else 
        {
            j++;
        }
    }

    for (int a : result) 
    {
        cout << a << " ";
    }
}