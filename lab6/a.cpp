#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quickSort(vector<char>& arr, int l, int r)
{
    char p = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSort(arr, l, j);
    if (i < r)
        quickSort(arr, i, r);
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> a, b;

    for (char& c : s)
    {
        switch (c)
        {
        case 'a':
            a.push_back(c);
            break;
        case 'e':
            a.push_back(c);
            break;
        case 'i':
            a.push_back(c);
            break;
        case 'o':
            a.push_back(c);
            break;
        case 'u':
            a.push_back(c);
            break;
        
        default:
            b.push_back(c);
            break;
        }
    }
    if (a.size())
        quickSort(a, 0, a.size() - 1);
    if (b.size())
        quickSort(b, 0, b.size() - 1);

    // instead of quickSort() you can use std::sort from algorithm header

    for (char& c : a)
        cout << c;
    for (char& c : b)
        cout << c;

    return 0;
}