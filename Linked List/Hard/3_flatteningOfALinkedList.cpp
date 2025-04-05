#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};
Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->child;
    }

    return head;
}
Node *flattenLinkedListBrute(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != nullptr)
    {
        // Node *nextNode = temp->next;
        Node *childTemp = temp;

        while (childTemp != nullptr)
        {
            arr.push_back(childTemp->data);
            childTemp = childTemp->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());

    head = convert(arr);
    return head;
}
Node *merge(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    Node *t1 = head1;
    Node *t2 = head2;
    while (t1 && t2)
    {
        if (t1->data <= t2->data)
        {
            res->child = t1;
            res = res->child;
            t1 = t1->child;
        }
        else
        {
            res->child = t1;
            res = res->child;
            t2 = t2->child;
        }
        res->next = nullptr;
    }
    if (t1)
    {
        res->child = t1;
    }
    else
    {
        res->child = t2;
    }
    if (dummyNode->child)
        dummyNode->child->next = nullptr;

    return dummyNode->child;
}
Node *flattenLinkedListOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *mergedHead = flattenLinkedListOptimal(head->next);
    return merge(head, mergedHead);
}
int main()
{

    return 0;
}