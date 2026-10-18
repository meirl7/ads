#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long x;
    while (cin >> x)
    {
        pq.push(x);
    }

    long long cost = 0;

    while(pq.size() > 1)
    {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long c = a + b;
        cost += c;
        pq.push(c);
    }

    cout << cost << endl;
}