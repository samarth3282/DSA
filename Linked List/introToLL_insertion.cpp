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

Node *insertNode(int data, Node *head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}
Node *insertHead(Node *head)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}
Node *convertToLL(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
Node *insertTail(Node *head)
{
    Node *temp = head;
    int data;
    cout << "Enter your data: ";
    cin >> data;
    Node *newNode = new Node(data);
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // newNode->next = nullptr;
    return head;
}
Node *insertAtIndex(Node *head, int n)
{
    Node *temp = head;
    Node *prev = nullptr;
    int cnt = 1;
    int data;
    cout << "Enter your data: ";
    cin >> data;
    if (n == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    while (temp && cnt < n)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    if (cnt == n)
    {
        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = temp;
    }
    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToLL(v);
    // cout << "HELLO";
    printLL(head);
    // head = insertHead(head);
    head = insertAtIndex(head, 7);
    printLL(head);

    return 0;
}