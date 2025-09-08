// /*

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
// */

class Solution
{
public:
    Node *findMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->data < l2->data)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    Node *mergeSort(Node *head)
    {
        // code here
        if (!head || !head->next)
            return head;

        Node *mid = findMiddle(head);
        Node *rightHead = mid->next;
        mid->next = nullptr;
        // Node *left = mid;
        Node *left = mergeSort(head);
        Node *right = mergeSort(rightHead);

        return merge(left, right);
    }
};