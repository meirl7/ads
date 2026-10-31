#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> st;

    while (n--)
    {
        int a;
        cin >> a;
        
        while (!st.empty() && st.top() >= a)
            st.pop();
        if (!st.empty())
            cout << st.top() << " ";
        else
            cout << -1 << " ";
        st.push(a);
    }

}