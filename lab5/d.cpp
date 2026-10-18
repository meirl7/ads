#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap

    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;

    while(true)
    {
        if (pq.top() >= m)
        {
            break;
        }
        if (pq.size() < 2)
        {
            ans = -1;
            break;
        }

        long long d1 = pq.top(); pq.pop();
        long long d2 = pq.top(); pq.pop();
        long long dn = d1 + 2 * d2;
        pq.push(dn);
        ans++;
    }
    cout << ans;
}