#include <bits/stdc++.h>
using namespace std;

// Node class representing each element in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize node with data
    Node(int data_)
    {
        data = data_;
        next = nullptr;
    }
};

// Brute Force Approach to find the middle element of the linked list
// --------------------------------------------------------------
// Approach:
// 1. Traverse the linked list to count the total number of nodes.
// 2. Traverse the list again, stopping at the middle index.
// 3. Return the node at that position.
// 
// Time Complexity: O(n) — Traversing the list twice
// Space Complexity: O(1) — No extra data structures used
Node *findMiddleElementBrute(Node *head)
{
    Node *temp = head;
    int count = 0;

    // First pass to count the total number of nodes
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    // Calculate the middle index
    int mid = count / 2;

    // Second pass to reach the middle node
    temp = head;
    count = 0;
    while (count < mid)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}

// Optimal Approach (Two Pointers - Slow & Fast Pointer)
// --------------------------------------------------------------
// Approach:
// 1. Initialize two pointers: `slow` and `fast`, both starting at the head.
// 2. Move `slow` one step at a time and `fast` two steps at a time.
// 3. When `fast` reaches the end (or becomes `nullptr`), `slow` will be at the middle node.
//
// Time Complexity: O(n) — Only one pass required
// Space Complexity: O(1) — No extra data structures used
Node *findMiddleOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // Fast moves two steps while slow moves one step
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // `slow` will now point to the middle node
    return slow;
}

int main()
{
    // Sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Testing Brute Force Approach
    Node *middleBrute = findMiddleElementBrute(head);
    cout << "Middle element (Brute Force): " << middleBrute->data << endl;

    // Testing Optimal Approach
    Node *middleOptimal = findMiddleOptimal(head);
    cout << "Middle element (Optimal): " << middleOptimal->data << endl;

    return 0;
}
