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
// Node *convertToOddEvenLinkedListUsingDataManipulation(Node *head)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }

//     vector<int> v;
//     Node *temp = head;
//     while (temp != nullptr && temp->next != nullptr)
//     {
//         v.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if (temp)
//         v.push_back(temp->data);
//     temp = head->next;
//     while (temp != nullptr && temp->next != nullptr)
//     {
//         v.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if (temp)
//         v.push_back(temp->data);

//     temp = head;
//     int i = 0;
//     while (temp)
//     {
//         temp->data = v[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

Node *convertToOddEvenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v1;
    Node *head = convertToLL(v);
    printLL(head);
    // head = convertToOddEvenLinkedListUsingDataManipulation(head);
    head = convertToOddEvenLinkedList(head);
    printLL(head);
    return 0;
}