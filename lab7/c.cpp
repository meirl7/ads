#include <iostream>
#include <vector>

using namespace std;


struct Row 
{
    vector<int> elements;
    long long sum;
};

bool compareRows(const Row& a, const Row& b) 
{
    if (a.sum != b.sum) 
    {
        return a.sum > b.sum;
    }
    return a.elements < b.elements;
}

void merge(vector<Row>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Row> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (compareRows(L[i], R[j])) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Row>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int main() 
{
    int n, m;
    cin >> n >> m;

    vector<Row> arr(n);

    for (int i = 0; i < n; i++) 
    {
        arr[i].elements.resize(m);
        arr[i].sum = 0;
        for (int j = 0; j < m; j++) 
        {
            cin >> arr[i].elements[j];
            arr[i].sum += arr[i].elements[j];
        }
    }

    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cout << arr[i].elements[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}