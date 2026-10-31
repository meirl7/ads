#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void solve(int n)
{
    deque<int> d;
    for (int i = n; i >= 1; i--)
    {
        d.push_front(i);
        int k = i % d.size();
        if (k > 0)
            rotate(d.begin(), d.end() - k, d.end());
    }

    for (int& i : d)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a;
        cin >> a;
        solve(a);
    }
}