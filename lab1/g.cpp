#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> st;

    string s;
    cin >> s;

    for (char& c : s)
    {
        if (!st.empty() && st.top() == c)
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    cout << (st.empty() ? "YES" : "NO");
}