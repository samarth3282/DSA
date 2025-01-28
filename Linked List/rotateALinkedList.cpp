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
Node *rotateALinkedListBrute(Node *head, int k)
{
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        Node *lastNode = temp->next;
        temp->next = nullptr;
        lastNode->next = head;
        head = lastNode;
    }
    return head;
}

Node *rotateALinkedListBetter(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }
    Node *temp = head;
    int length = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        length++;
    }
    temp->next = head;
    k = k % length;
    int iterations = length - k;
    while (iterations)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main()
{

    return 0;
}