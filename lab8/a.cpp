#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(2 * n);

    unordered_set<string> set;

    const uint64_t modulo = 1000000007;
    
    for (auto& s : arr)
    {
        cin >> s;
        set.insert(s);
    }
    for (auto& s : arr)
    {
        uint64_t h = 0, p = 1;
        for (char& c : s)
        {
            h = (h + (c - 47) * p) % modulo;
            p = p * 11 % modulo;
        }
        if (set.count(to_string(h)))
        {
            cout << "Hash of string \"" << s << "\" is " << h << endl;
        }
    }
}