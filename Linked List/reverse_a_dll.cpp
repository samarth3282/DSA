#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data_)
    {
        data = data_;
        next = nullptr;
        prev = nullptr;
    }
};

Node *reverseDll(Node *head)
{
    Node *prevNode = nullptr;
    Node *currNode = head;
    while (currNode)
    {
        prevNode = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = prevNode;
        currNode = currNode->prev;
    }
    if (prevNode)
    {
        head = prevNode->prev;
    }
    return head;
}
int main()
{

    return 0;
}