#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int value;

    ListNode(int value) : next(nullptr), value(value) {}
};

int main()
{
    int n;
    cin >> n;

    ListNode* head;
    ListNode* prev = nullptr;
    ListNode* temp = nullptr;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        temp = new ListNode(num);

        if (i == 0)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;
    }

    int i = 0;
    while (head != nullptr)
    {
        if (i++ % 2 == 0)
            cout << head->value << " ";
        head = head->next;
    }
}