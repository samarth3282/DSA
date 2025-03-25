#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data_, Node *prev_ = nullptr, Node *next_ = nullptr)
        : data(data_), prev(prev_), next(next_) {}
};

// Utility function to print DLL
void printDLL(Node *head)
{
    if (!head)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "NULL <--> ";
    while (temp)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert new node at the head
Node *insertHead(Node *head, int data)
{
    Node *newNode = new Node(data, nullptr, head);
    if (head)
        head->prev = newNode;
    return newNode;
}

// Convert vector to DLL
Node *convertToDLL(const vector<int> &v)
{
    if (v.empty())
        return nullptr;

    Node *head = new Node(v[0]);
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        temp->next = new Node(v[i], temp);
        temp = temp->next;
    }
    return head;
}

// Insert node before tail
Node *insertBeforeTail(Node *head, int data)
{
    if (!head)
        return new Node(data);

    if (!head->next) // Only one node in the list
        return insertHead(head, data);

    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data, temp, temp->next);
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Insert node at the end
Node *insertNodeAtEnd(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
        return newNode;

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Insert node before the kth element
Node *insertBeforeKthElement(Node *head, int k, int data)
{
    if (k < 1)
    {
        cout << "Invalid position! k should be >= 1.\n";
        return head;
    }

    Node *newNode = new Node(data);
    if (!head)
    {
        if (k != 1)
        {
            cout << "Out of Bounds! List is empty.\n";
            delete newNode;
            return nullptr;
        }
        return newNode;
    }

    if (k == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node *temp = head;
    int count = 1;

    while (temp && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (!temp || !temp->next)
    {
        cout << "Out of Bounds! Position exceeds list length.\n";
        delete newNode;
        return head;
    }

    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
    return head;
}

// Main Function
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToDLL(v);

    cout << "Initial DLL:\n";
    printDLL(head);

    // Insert operations
    head = insertBeforeKthElement(head, 2, 10);
    cout << "After inserting 10 before 2nd element:\n";
    printDLL(head);

    head = insertBeforeTail(head, 20);
    cout << "After inserting 20 before tail:\n";
    printDLL(head);

    head = insertNodeAtEnd(head, 30);
    cout << "After inserting 30 at the end:\n";
    printDLL(head);

    head = insertHead(head, 40);
    cout << "After inserting 40 at the head:\n";
    printDLL(head);

    return 0;
}
