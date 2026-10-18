#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comparator(string& s1, string& s2)
{
    int y1 = stoi(s1.substr(6, 4));
    int y2 = stoi(s2.substr(6, 4));
    if (y1 != y2)
        return y1 < y2;

    int m1 = stoi(s1.substr(3, 2));
    int m2 = stoi(s2.substr(3, 2));
    if (m1 != m2)
        return m1 < m2;

    int d1 = stoi(s1.substr(0, 2));
    int d2 = stoi(s2.substr(0, 2));
    
    return d1 < d2;
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), comparator);

    for (string& s : arr)
    {
        cout << s << endl;
    }
}