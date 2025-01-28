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

Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    Node *newHead = reverseLL(head->next);

    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
bool checkPalindromeBrute(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (st.top() != temp->data)
        {
            return false;
        }
        temp = temp->next;
        st.top();
    }
    return true;
}

bool checkPalindromeOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLL(slow->next);
    Node *first = head;
    Node *second = newHead;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}
int main()
{

    return 0;
}