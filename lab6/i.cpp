#include <iostream>
#include <vector>
#include <string>

using namespace std;

void quickSort(string& arr, int l, int r, bool (*comp)(char, char))
{
    char p = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (comp(arr[i], p)) i++;
        while (comp(p, arr[j])) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSort(arr, l, j, comp);
    if (i < r)
        quickSort(arr, i, r, comp);
}

int main()
{
    string s;
    cin >> s;
    
    quickSort(s, 0, s.size() - 1, [](char a, char b){return a < b;});

    cout << s;
}