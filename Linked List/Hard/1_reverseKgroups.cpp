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
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
Node *insertNode(Node *head, int data)
{
    if (!head)
        return new Node(data);

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new Node(data);
    return head;
}
Node *findKthNode(Node *temp, int k)
{
    int i = 1;
    while (temp && i < k)
    {
        i++;
        temp = temp->next;
    }
    return temp;
}

void reverseLL(Node *temp)
{
    Node *currNode = temp;
    Node *prevNode = nullptr;
    Node *nextNode = nullptr;
    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
}
Node *reverseLLinGroupsOfK(Node *head, int k)
{
    Node *currentGroupHead = head;
    Node *previousGroupTail = nullptr;

    while (currentGroupHead != nullptr)
    {
        Node *kthNode = findKthNode(currentGroupHead, k);
        if (kthNode == nullptr)
        {
            if (previousGroupTail)
                previousGroupTail->next = currentGroupHead;
            break;
        }

        Node *nextGroupHead = kthNode->next;
        kthNode->next = nullptr;

        reverseLL(currentGroupHead);

        if (currentGroupHead == head)
            head = kthNode;
        else
        {
            previousGroupTail->next = kthNode;
        }

        previousGroupTail = currentGroupHead;
        currentGroupHead = nextGroupHead;
    }
    return head;
}

int main()
{
    Node *head = nullptr;

    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    for (int i = 1; i <= 8; i++)
        head = insertNode(head, i);

    cout << "Original List: ";
    printList(head);

    int k = 3; // Size of groups
    head = reverseLLinGroupsOfK(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(head);

    return 0;
    return 0;
}