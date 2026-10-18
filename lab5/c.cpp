#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, less<long long>> pq; // max heap

    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;

    while(m--)
    {
        long long a = pq.top();
        pq.pop();

        ans += a;

        if (a > 1)
        {
            pq.push(a - 1);
        }
    }
    cout << ans;
}