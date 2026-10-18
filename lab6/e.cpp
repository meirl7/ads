#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++)
    {
        vector<int> col(n);
        for (int i = 0; i < n; i++) {
            col[i] = matrix[i][j];
        }

        sort(col.begin(), col.end(), [](const int& a, const int& b){
            return a > b;
        });

        for (int i = 0; i < n; i++) 
        {
            matrix[i][j] = col[i];
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}