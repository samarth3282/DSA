#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data_)
    {
        data = data_;
        next = nullptr;
    }
};

Node *deleteMiddle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    int mid = count / 2;
    temp = head;
    Node *prev = nullptr;
    while (mid--)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return head;
}
int main()
{

    return 0;
}