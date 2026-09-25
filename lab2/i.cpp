#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    string data;
    ListNode* next;
    ListNode* prev;
};

ListNode* node = nullptr;
vector<string> answers;

void add_front(string data)
{
    if (node == nullptr)
        node = new ListNode{data, nullptr, nullptr};
    else
    {
        ListNode* l = node;
        while (l != nullptr)
        {
            if (l->prev == nullptr)
            {
                l->prev = new ListNode{data, l, nullptr};
                break;
            }
            l = l->prev;
        }
    }
    answers.emplace_back("ok");
}
void add_back(string data)
{
    if (node == nullptr)
        node = new ListNode{data, nullptr, nullptr};
    else
    {
        ListNode* l = node;
        while (l != nullptr)
        {
            if (l->next == nullptr)
            {
                l->next = new ListNode{data, nullptr, l};
                break;
            }
            l = l->next;
        }
    }
    answers.emplace_back("ok");
}

void erase_front()
{
    if (!node)
    {
        answers.emplace_back("error");
        return;
    }
    ListNode* l = node;
    while (l->prev != nullptr)
    {
        l = l->prev;
    }
    answers.emplace_back(l->data);
    ListNode* next_node = l->next;
    if (next_node != nullptr)
    {
        next_node->prev = nullptr;
        if (node == l) node = next_node;
    }
    else
        node = nullptr;
    delete l;
}

void erase_back()
{
    if (!node)
    {
        answers.emplace_back("error");
        return;
    }
    ListNode* l = node;
    while (l->next != nullptr)
    {
        l = l->next;
    }
    answers.emplace_back(l->data);
    ListNode* prev_node = l->prev;
    if (prev_node != nullptr)
    {
        prev_node->next = nullptr;
        if (node == l) node = prev_node;
    }
    else
        node = nullptr;
    delete l;
}

void front()
{
    if (!node)
    {
        answers.emplace_back("error");
        return;
    }
    ListNode* l = node;
    while (l->prev != nullptr)
    {
        l = l->prev;
    }
    answers.emplace_back(l->data);
}

void back()
{
    if (!node)
    {
        answers.emplace_back("error");
        return;
    }
    ListNode* l = node;
    while (l->next != nullptr)
    {
        l = l->next;
    }
    answers.emplace_back(l->data);
}

void clear()
{
    if (node)
        delete node;
    node = nullptr;
    answers.emplace_back("ok");
}

int main()
{
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "exit")
        {
            answers.emplace_back("goodbye");
            break;
        }
        if (cmd == "add_front")
        {
            string arg;
            cin >> arg;
            add_front(arg);
        }
        else if (cmd == "add_back")
        {
            string s;
            cin >> s;
            add_back(s);
        }
        else if (cmd == "erase_front")
        {
            erase_front();
        }
        else if (cmd == "erase_back")
        {
            erase_back();
        }
        else if (cmd == "front")
        {
            front();
        }
        else if (cmd == "back")
        {
            back();
        }
        else if (cmd == "clear")
        {
            clear();
        }
    }
    for (const auto& s : answers)
    {
        cout << s << "\n";
    }
}