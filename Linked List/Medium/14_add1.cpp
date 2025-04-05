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
Node *reverseLL(Node *head)
{
    Node *prevNode = nullptr;
    Node *currNode = head;
    Node *nextNode = nullptr;
    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
Node *add1(Node *head)
{
    Node *reverseHead = reverseLL(head);
    Node *temp = reverseHead;
    int carry = 1;
    while (temp)
    {
        int sum = carry + temp->data;
        temp->data = sum % 10;
        carry = sum / 10;
        if (carry == 0)
        {
            break;
        }
        if (carry != 0 && temp->next == nullptr)
        {
            temp->next = new Node(carry);
            carry = 0;
        }

        temp = temp->next;
    }
    return reverseLL(reverseHead);
}
int helper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }
    int carry = helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}
Node *addOneOptimal(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
int main()
{

    return 0;
}
