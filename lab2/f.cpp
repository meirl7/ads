#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* merge(Node* l1, Node* l2)
{
    Node* head = nullptr;
    Node** tail = &head;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            *tail = l1;
            l1 = l1->next;
        }
        else
        {
            *tail = l2;
            l2 = l2->next;
        }
        tail = &((*tail)->next);
    }
    *tail = l1 ? l1 : l2;
    return head;
}

Node* readNode(int len)
{
    Node* head = nullptr;
    Node** tail = &head;

    for (int i = 0; i < len; ++i)
    {
        int val;
        cin >> val;
        *tail = new Node(val);
        tail = &((*tail)->next);
    }
    return head;
}

void print(Node* head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    int n, m;
    cin >> n;
    Node* l1 = readNode(n);
    cin >> m;
    Node* l2 = readNode(m);
    Node* mr = merge(l1, l2);
    print(mr);
}