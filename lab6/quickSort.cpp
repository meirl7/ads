#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int l, int r)
{
    int p = arr[(l + r) / 2];
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
    vector<int> arr = {23, 34, 54,4 ,1,32 ,4 ,23 ,24 };

    quickSort(arr, 0, arr.size() - 1);

    for (int a : arr)
    {
        cout << a << " ";
    }
}