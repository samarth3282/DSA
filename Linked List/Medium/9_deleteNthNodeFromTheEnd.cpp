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
Node *deleteNthNodeFromTheEndBrute(Node *head, int n)
{
    Node *temp = head;
    int length = 0;
    while (temp)
    {
        temp = temp->next;
        length++;
    }

    int position = length - n + 1;
    if (position <= 0 || position > length)
    {
        return head;
    }
    temp = head;
    Node *prevNode = nullptr;
    for (int i = 0; i < position; i++)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteNthNodeFromTheEnd(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    for (int i = 0; i < n; i++)
    {
        if (fast == nullptr)
        {
            return head;
        }
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *nodeToBeDeleted = slow->next;
    Node *prev = slow;
    prev->next = nodeToBeDeleted->next;
    nodeToBeDeleted->next = nullptr;
    delete nodeToBeDeleted;
    return head;
}
int main()
{

    return 0;
}