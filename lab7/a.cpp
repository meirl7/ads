#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void merge(vector<string>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (L[i].size() <= R[j].size()) 
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

void mergeSort(vector<string>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(const vector<string>& arr)
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

    string q;
    getline(cin, q);

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        vector<string> arr;
        stringstream ss(s);
        string temp;
        
        while (ss >> temp)
        {
            arr.push_back(temp);
        }
    
        mergeSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }
}