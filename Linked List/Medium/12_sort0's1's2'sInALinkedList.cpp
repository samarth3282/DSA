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
Node *convertToLL(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}
void printLL(Node *head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty!";
        return;
    }

    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *sortZerosOnesTwosInALinkedList(Node *head)
{
    int cnt_zeros = 0;
    int cnt_ones = 0;
    int cnt_twos = 0;
    Node *temp = head;
    while (temp)
    {
        switch (temp->data)
        {
        case 0:
            cnt_zeros++;
            break;
        case 1:
            cnt_ones++;
            break;
        case 2:
            cnt_twos++;
            break;
        }
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < cnt_zeros; i++)
    {
        temp->data = 0;
        temp = temp->next;
    }
    for (int i = 0; i < cnt_ones; i++)
    {
        temp->data = 1;
        temp = temp->next;
    }
    for (int i = 0; i < cnt_twos; i++)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

Node *sortZerosOnesTwosInALinkedListByChangingLinks(Node *head)
{
    Node *zeroHead = nullptr;
    Node *zeroTail = nullptr;
    Node *oneHead = nullptr;
    Node *oneTail = nullptr;
    Node *twoHead = nullptr;
    Node *twoTail = nullptr;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            if (zeroHead == nullptr)
            {
                zeroHead = temp;
                zeroTail = temp;
            }
            else
            {
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            }
        }
        if (temp->data == 1)
        {
            if (oneHead == nullptr)
            {
                oneHead = temp;
                oneTail = temp;
            }
            else
            {
                oneTail->next = temp;
                oneTail = oneTail->next;
            }
        }
        if (temp->data == 2)
        {
            if (twoHead == nullptr)
            {
                twoHead = temp;
                twoTail = temp;
            }
            else
            {
                twoTail->next = temp;
                twoTail = twoTail->next;
            }
        }
    }
    if (zeroTail)
    {
        zeroTail->next = nullptr;
    }
    if (oneTail)
    {
        oneTail->next = nullptr;
    }
    if (twoTail)
    {
        twoTail->next = nullptr;
    }
    if (zeroTail)
        zeroTail->next = oneHead ? oneHead : twoHead;
    if (oneTail)
        oneTail->next = twoHead;
    return zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
}
int main()
{
    vector<int> v = {0, 1, 2, 1, 1, 0, 2, 2, 0};
    Node *head = convertToLL(v);
    printLL(head);
    head = sortZerosOnesTwosInALinkedList(head);
    return 0;
}