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
Node *seggregatOddEven(Node *head)
{
    Node *evenHead = nullptr;
    Node *evenTail = nullptr;
    Node *oddHead = nullptr;
    Node *oddTail = nullptr;
    Node *temp = head;
    while (temp)
    {
        if (temp->data % 2 == 0)
        {
            if (!evenHead)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (!oddHead)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
    }
    if (evenTail)
    {
        evenTail->next = oddHead;
    }
    if (oddTail)
    {
        oddTail->next = nullptr;
    }
    return evenHead ? evenHead : oddHead;
}

Node *segregateOddEven(Node *head)
{
    Node *evenHead = nullptr;
    Node *evenTail = nullptr;
    Node *oddHead = nullptr;
    Node *oddTail = nullptr;

    Node *temp = head;

    while (temp)
    {
        if (temp->data % 2 == 0)
        {

            if (evenHead == nullptr)
            {
                evenHead = temp;
                evenHead = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == nullptr)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
            }
        }
    }
    if (evenTail)
    {
        evenTail->next = oddHead;
    }
    if (oddTail)
    {
        oddTail->next = nullptr;
    }
    return evenHead;
}

int main()
{

    return 0;
}