#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2)
{
    int i = 0, j = 0, k = 0;
    size_t s1 = arr1.size(), s2 = arr2.size();

    vector<int> arr;
    arr.reserve(s1 + s2);


    while (i < s1 && j < s2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr.push_back(arr2[j]);
            j++;
        }
    }

    while (i < s1)
    {
        arr.push_back(arr1[i]);
        i++;
    }

    while (j < s2)
    {
        arr.push_back(arr2[j]);
        j++;
    }

    return arr;
}

void printArray(const vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << (i + 1 == arr.size() ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> merged = merge(a, b);
    
    printArray(merged);
}