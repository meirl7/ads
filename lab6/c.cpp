#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int d = -1;
    for (int i = 0; i < n - 1; i++) 
    {
        int diff = arr[i + 1] - arr[i];
        if (d == -1 || diff < d) 
        {
            d = diff;
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i + 1] - arr[i] == d) 
        {
            ans.push_back({arr[i], arr[i + 1]});
        }
    }

    for (const auto& p : ans) 
    {
        cout << p.first << " " << p.second << " ";
    }

    return 0;
}