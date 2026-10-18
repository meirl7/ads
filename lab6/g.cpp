#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<pair<string, string>> arr;

    for (int i = 0; i < n; i++) 
    {
        string a, b;
        cin >> a >> b;

        bool found = false;
        
        for (auto& it : arr) 
        {
            if (it.second == a) 
            {
                it.second = b;
                found = true;
                break;
            }
        }

        if (!found)
            arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    cout << arr.size() << endl;

    for (const auto& i : arr) 
    {
        cout << i.first << " " << i.second << "\n";
    }
}