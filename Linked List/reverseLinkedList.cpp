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
Node *reverseLinkedListIteraive(Node *head)
{
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    Node *currNode = head;
    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
};

Node *reverseLinkedListRecursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *newHead = reverseLinkedListRecursive(head->next);

    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
int main()
{

    return 0;
}