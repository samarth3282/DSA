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

Node *findMiddleElementBrute(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    temp = head;
    count = 0;
    while (count < mid)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

Node *findMiddleOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{

    return 0;
}