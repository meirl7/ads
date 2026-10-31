#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> boris, nursik;

    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        boris.push(n);
    }

    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        nursik.push(n);
    }

    int moves = 0;

    while (!boris.empty() && !nursik.empty())
    {
        moves++;
        int b = boris.front();
        int n = nursik.front();
        boris.pop();
        nursik.pop();

        bool bw = false;

        if (b == 0 && n == 9)
        {
            bw = true;
        }
        else if (b == 9 && n == 0)
        {
            bw = false;
        }
        else if (b > n)
        {
            bw = true;
        }

        if (bw)
        {
            boris.push(b);
            boris.push(n);
        }
        else
        {
            nursik.push(b);
            nursik.push(n);
        }
    }
    if (boris.empty())
    {
        cout << "Nursik " << moves;
    }
    else
    {
        cout << "Boris " << moves;
    }
}