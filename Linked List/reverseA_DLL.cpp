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
    Node(int data_, Node *next_, Node *prev_)
    {
        data = data_;
        next = next_;
        prev = prev_;
    }
};
Node *convertToDLL(vector<int> &v)
{
    if (v.empty())
    {
        return nullptr;
    }

    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i], nullptr, temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void printDLL(Node *head)
{
    Node *temp = head;
    cout << "NULL ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
Node *reverseDLL(Node *head, vector<int> &stack)
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
    return prevNode->prev;
}
int main()
{
    vector<int> stack;
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToDLL(v);
    printDLL(head);
    head = reverseDLL(head, stack);
    printDLL(head);
    return 0;
}