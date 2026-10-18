#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int arr[26] = {0};

    for (char& c : s)
        arr[static_cast<int>(c) - 97]++;
    
    for (int i = 0; i < 26; i++)
    {
        char c = static_cast<char>(i + 97);
        for (int j = 0; j < arr[i]; j++)
            cout << c;
    }
}