#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *random;
    // Constructor to initialize node with data
    Node(int data_)
    {
        data = data_;
        next = nullptr;
        random = nullptr;
    }
};

Node *cloneLinkedListWithRandomPointerBrute(Node *head)
{
    unordered_map<Node *, Node *> cloneOf;
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->data);
        cloneOf[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        cloneOf[temp]->next = cloneOf[temp->next];
        cloneOf[temp]->random = cloneOf[temp->random];
        temp = temp->next;
    }
    // temp = head;
    return cloneOf[head];
}

Node *cloneLinkedListWithRandomPointerOptimal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
    }
    temp = head;
    while (temp)
    {
        temp->next->random = temp->random ? temp->random->next : nullptr;
        temp = temp->next->next;
    }
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    temp = head;
    while (temp)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
int main()
{

    return 0;
}