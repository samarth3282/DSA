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

// Brute Force Approach to Rotate a Linked List
// --------------------------------------------------------------
// Approach:
// 1. For each rotation (total k rotations):
//    - Traverse the list to reach the second last node.
//    - Detach the last node and move it to the front.
// 2. Repeat this k times.
//
// Time Complexity: O(n * k) — Each rotation requires O(n) traversal.
// Space Complexity: O(1) — No extra data structures used.
Node *rotateALinkedListBrute(Node *head, int k)
{
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;

        // Traverse to the second last node
        while (temp->next->next)
        {
            temp = temp->next;
        }

        // Last node becomes the new head
        Node *lastNode = temp->next;
        temp->next = nullptr;
        lastNode->next = head;
        head = lastNode;
    }

    return head;
}

// Optimal Approach to Rotate a Linked List
// --------------------------------------------------------------
// Approach:
// 1. Find the length of the linked list by traversing it.
// 2. Connect the tail to the head, making the list circular.
// 3. Calculate the effective rotations: `k = k % length` (important for large k).
// 4. Traverse the list until you reach the node just before the new head.
// 5. Break the circular link and update the head pointer.
//
// Time Complexity: O(n) — Only one pass to calculate length and one pass to adjust links.
// Space Complexity: O(1) — No extra data structures used.
Node *rotateALinkedListOptimal(Node *head, int k)
{
    // Edge cases: Empty list, single node, or no rotations required
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }

    // Step 1: Find the length of the list
    Node *temp = head;
    int length = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        length++;
    }

    // Step 2: Connect the tail to the head (circular link)
    temp->next = head;

    // Step 3: Calculate effective rotations
    k = k % length;              // Prevent redundant full rotations
    int iterations = length - k; // Number of steps to reach the new tail

    // Step 4: Traverse to the node just before the new head
    while (iterations--)
    {
        temp = temp->next;
    }

    // Step 5: Break the circular link and update the head
    head = temp->next;
    temp->next = nullptr;

    return head;
}

// Utility function to print the linked list
void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printLL(head);

    // Testing Brute Force Approach
    Node *bruteResult = rotateALinkedListBrute(head, 2);
    cout << "After Rotating by 2 (Brute Force): ";
    printLL(bruteResult);

    // Resetting linked list for optimal approach
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Testing Optimal Approach
    Node *optimalResult = rotateALinkedListOptimal(head, 2);
    cout << "After Rotating by 2 (Optimal): ";
    printLL(optimalResult);

    return 0;
}
