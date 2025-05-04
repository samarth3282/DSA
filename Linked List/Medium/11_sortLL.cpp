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

Node *sortLLBrute(Node *head)
{
    vector<int> v;
    Node *temp = head;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end(), false);

    temp = head;
    int start = 0;
    while (temp && start < v.size())
    {
        temp->data = v[start];
        start++;
        temp = temp->next;
    }

    return head;
}

Node *sortLLOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *middleHead = findMiddle(head);
    Node *rightHead = middleHead->next;
    middleHead->next = nullptr;

    Node *leftSorted = sortLLOptimal(head);
    Node *rightSorted = sortLLOptimal(rightHead);

    mergeLL(leftSorted, rightSorted);
}
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeLL(Node *leftHead, Node *rightHead)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (leftHead && rightHead)
    {
        if (leftHead->data < rightHead->data)
        {
            temp->next = leftHead;
            temp = temp->next;
            leftHead = leftHead->next;
        }
        else
        {
            temp->next = rightHead;
            temp = temp->next;
            rightHead = rightHead->next;
        }
    }
    if (leftHead)
    {
        temp->next = leftHead;
    }
    if (rightHead)
    {
        temp->next = rightHead;
    }
    return dummyNode->next;
}
int main()
{

    return 0;
}