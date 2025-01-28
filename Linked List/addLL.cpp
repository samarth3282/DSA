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
Node *addLL(Node *head1, Node *head2)
{
    int carry = 0;
    int sum;
    Node *t1 = head1;
    Node *t2 = head2;
    Node *dummyNode = new Node(-1);
    Node *currNode = dummyNode;
    while (t1 || t2)
    {
        sum = carry;
        if (t1)
        {
            sum = sum + t1->data;
        }
        if (t2)
        {
            sum = sum + t2->data;
        }
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        currNode->next = newNode;
        currNode = currNode->next;
        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        currNode->next = newNode;
        currNode = currNode->next;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    Node *head1 = convertToLL(v1);
    Node *head2 = convertToLL(v2);
    printLL(head1);
    printLL(head2);
    Node *head = addLL(head1, head2);
    printLL(head);
    return 0;
}