#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int value) : value(value), next(nullptr) {}
};

int main()
{
    int n;
    cin >> n;

    ListNode* head;
    {
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;
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
    }
    int i = 0;
    while (head)
    {
        if (i++ != n / 2)
            cout << head->value << " ";
        head = head->next;
    }
}