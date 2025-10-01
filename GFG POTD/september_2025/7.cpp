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
        next = NULL;
    }
};
// */

class Solution
{
public:
    Node *mergeTwoLists(Node *head1, Node *head2)
    {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        while (head1)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        while (head2)
        {
            temp->next = head2;
            temp = temp->next;

            head2 = head2->next;
        }
        return dummy->next;
    }
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        Node *merged = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            merged = mergeTwoLists(merged, arr[i]);
        }
        return merged;
    }
};