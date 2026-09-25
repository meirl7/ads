#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> data;
    string inputString;

    for (int i = 0; i < n; ++i)
    {
        cin >> inputString;
        if (data.empty() || data.back() != inputString)
        {
            data.push_back(inputString);
        }
    }
    cout << data.size() << "\n";
    for (const auto& s : data)
    {
        cout << s << "\n";
    }
}