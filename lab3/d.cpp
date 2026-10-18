#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search_right(const vector<int>& arr, long long val) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= val) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        
        int count = binary_search_right(a, x);
        long long total_power = pref[count];
        
        cout << count << " " << total_power << "\n";
    }

    return 0;
}