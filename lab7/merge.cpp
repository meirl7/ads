#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2)
{
    
    int i = 0, j = 0, k = 0;
    size_t s1 = arr1.size(), s2 = arr2.size();

    vector<int> arr(s1 + s2);


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

int main()
{
    vector<int> a1 = {1, 2, 6, 8, 9};
    vector<int> a2 = {3, 5, 7, 8, 9, 10, 22};

    vector<int> a3 = merge(a1, a2);

    for (int i : a3)
    {
        cout << i << " ";
    }
}