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
    cout << "NULL <--> ";
    while (temp)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node *deleteKthElement(Node *head, int k)
{
    if (head == nullptr)
    {
        cout << "List is Empty!";
        return head;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (temp != nullptr && count < k)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Out of bounds!";
        return head;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    delete temp;
    return head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToDLL(v);
    printDLL(head);
    head = deleteKthElement(head, 3);
    // head = deleteTail(head);
    // head = deleteHead(head);
    printDLL(head);
    return 0;
}