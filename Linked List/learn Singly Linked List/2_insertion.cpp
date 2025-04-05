#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node data and next pointer
    Node(int data_)
    {
        data = data_;
        next = nullptr;
    }
};

/**
 * Function: insertNodeAtEnd
 * -------------------------
 * Inserts a node at the end of the linked list.
 *
 * @param data - Data to insert.
 * @param head - Pointer to the head of the linked list.
 * @return Updated head pointer.
 *
 * Time Complexity: O(n) - Traverses the entire list.
 * Space Complexity: O(1) - No extra space used.
 */
Node *insertNodeAtEnd(int data, Node *head)
{
    Node *temp = head;

    // Traverse to the last node
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Insert new node at the end
    temp->next = new Node(data);
    return head;
}

/**
 * Function: insertNodeAtHead
 * --------------------------
 * Inserts a node at the beginning (head) of the linked list.
 *
 * @param head - Pointer to the head of the linked list.
 * @param data - Data to insert at the head.
 * @return Updated head pointer.
 *
 * Time Complexity: O(1) - Direct insertion at head.
 * Space Complexity: O(1) - No extra space used.
 */
Node *insertNodeAtHead(Node *head, int data)
{
    Node *newHead = new Node(data);
    newHead->next = head;
    return newHead;
}

/**
 * Function: convertToLinkedList
 * -----------------------------
 * Converts a vector into a linked list.
 *
 * @param arr - Vector containing list elements.
 * @return Pointer to the head of the newly created linked list.
 *
 * Time Complexity: O(n) - Traverses the entire array.
 * Space Complexity: O(1) - No extra space used apart from nodes.
 */
Node *convertToLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

/**
 * Function: printLinkedList
 * -------------------------
 * Prints the linked list in a clear format.
 *
 * @param head - Pointer to the head of the linked list.
 *
 * Time Complexity: O(n) - Traverses the entire list.
 */
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/**
 * Function: insertNodeAtTail
 * --------------------------
 * Inserts a node at the tail (end) of the linked list.
 *
 * @param head - Pointer to the head of the linked list.
 * @return Updated head pointer.
 *
 * Time Complexity: O(n) - Traverses the entire list.
 * Space Complexity: O(1) - No extra space used.
 */
Node *insertNodeAtTail(Node *head)
{
    Node *temp = head;
    int data;
    cout << "Enter your data: ";
    cin >> data;

    Node *newNode = new Node(data);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

/**
 * Function: insertNodeAtIndex
 * ---------------------------
 * Inserts a node at a specific index in the linked list.
 *
 * @param head - Pointer to the head of the linked list.
 * @param index - Index where the node should be inserted.
 * @param data - Data to insert.
 * @return Updated head pointer.
 *
 * Time Complexity: O(n) - Traverses the list to find the index.
 * Space Complexity: O(1) - No extra space used.
 */
Node *insertNodeAtIndex(Node *head, int index, int data)
{
    if (index < 0)
    {
        cout << "INVALID INDEX!" << endl;
        return head;
    }

    Node *newNode = new Node(data);

    // Insert at the head if index is 0
    if (index == 0)
    {
        newNode->next = head;
        return newNode;
    }

    int currIndex = 0;
    Node *currNode = head;
    while (currIndex < index - 1 && currNode != nullptr)
    {
        currNode = currNode->next;
        currIndex++;
    }

    // If index exceeds list size
    if (currNode == nullptr)
    {
        cout << "Index out of range!" << endl;
        delete newNode;
        return head;
    }

    // Insert new node at the correct position
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToLinkedList(v);

    cout << "Original Linked List: ";
    printLinkedList(head);

    cout << "\nInserting 6 at index 3..." << endl;
    head = insertNodeAtIndex(head, 3, 6);
    printLinkedList(head);

    cout << "\nInserting 0 at head..." << endl;
    head = insertNodeAtHead(head, 0);
    printLinkedList(head);

    cout << "\nInserting 9 at tail..." << endl;
    head = insertNodeAtEnd(9, head);
    printLinkedList(head);

    cout << "\nInserting at Invalid Index (-1)..." << endl;
    head = insertNodeAtIndex(head, -1, 99); 
    printLinkedList(head);

    cout << "\nInserting at Out-of-Bounds Index (15)..." << endl;
    head = insertNodeAtIndex(head, 15, 99); 
    printLinkedList(head);

    return 0;
}
