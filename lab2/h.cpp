#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    Node* next;
};

int main()
{
    int n;
    cin >> n;

    // O(n) speed input
    Node* head = nullptr;
    Node** tail = &head;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        *tail = new Node{a, nullptr};
        tail = &((*tail)->next);
    }

    int cur = head->val;
    int ans = head->val;
    for (Node* p = head->next; p; p = p->next)
    {
        cur = std::max(p->val, cur + p->val);
        ans = std::max(ans, cur);
    }
    cout << ans;
}