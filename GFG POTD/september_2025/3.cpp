#include <bits/stdc++.h>

// /*
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// */
class Solution
{
public:
    Node *reverse(Node *head)
    {
        // code here
        if (!head || !head->next)
            return head;
        Node *prevNode = nullptr;
        Node *currNode = head;
        // Node *nextNode = head->next;
        while (currNode)
        {
            prevNode = currNode->prev;
            currNode->prev = currNode->next;
            currNode->next = prevNode;
            currNode = currNode->prev;
        }
        return prevNode->prev;
    }
};