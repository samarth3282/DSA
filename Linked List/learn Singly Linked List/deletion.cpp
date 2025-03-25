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

// Function to convert a vector into a linked list
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding the linked list storage itself)
Node *convertToLL(vector<int> &v)
{
    Node *head = new Node(v[0]); // Create the head node
    Node *mover = head;          // Pointer to move through the list
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i]); // Create a new node
        mover->next = newNode;          // Link the current node to the new node
        mover = mover->next;            // Move to the newly created node
    }
    return head;
}

// Function to create a linked list from user input
// Time Complexity: O(n) where n = number of user entries
// Space Complexity: O(1) (excluding the linked list storage itself)
Node *createLL()
{
    Node *head = nullptr;
    Node *temp = nullptr;
    cout << "Enter your choice:\n1 : Insert\n0 : Exit\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter your data: ";
        int data;
        cin >> data;
        head = new Node(data); // Create the first node
        temp = head;

        do
        {
            cout << "Enter your choice:\n1 : Insert\n0 : Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter your data: ";
                int data_;
                cin >> data_;
                Node *newNode = new Node(data_);
                temp->next = newNode;
                temp = temp->next;
            }

        } while (choice != 0); // Repeat until user exits
    }
    else
    {
        cout << "No elements added.\n";
    }

    return head;
}

// Function to print the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
void printLL(Node *head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty!";
        return;
    }

    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to search for an element in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
void search(Node *head, int n)
{
    int cnt = 1; // Position counter
    while (head)
    {
        if (head->data == n)
        {
            cout << "Found! at " << cnt << " index";
            return;
        }
        head = head->next;
        cnt++;
    }
    cout << "Not Found!";
}

// Function to delete the head of the linked list
// Time Complexity: O(1)
// Space Complexity: O(1)
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr; // Empty list case

    Node *temp = head;
    head = head->next;
    delete temp; // Free the memory of the old head
    return head;
}

// Function to delete the tail of the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr; // Empty list or single node case
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next; // Free memory of the last node
    temp->next = nullptr;
    return head;
}

// Function to remove a node at a specific index
// Time Complexity: O(n)
// Space Complexity: O(1)
Node *removeIndex(Node *head, int index)
{
    if (index == 0) // If index is 0, delete the head
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int currIndex = 0;
    Node *currNode = head;
    while (currIndex < index - 1 && currNode != nullptr)
    {
        currNode = currNode->next;
        currIndex++;
    }

    if (currNode == nullptr || currNode->next == nullptr)
    {
        cout << "Invalid Index!";
        return head;
    }

    Node *nodeToDelete = currNode->next;
    currNode->next = nodeToDelete->next;
    delete nodeToDelete; // Free memory of the deleted node
    return head;
}

// Function to remove an element by value
// Time Complexity: O(n)
// Space Complexity: O(1)
Node *removeElement(Node *head, int num)
{
    if (head == nullptr)
    {
        cout << "Linked List is empty!";
        return head;
    }

    // Special case: If head holds the target value
    if (head->data == num)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == num)
        {
            prev->next = prev->next->next;
            delete temp; // Free memory of the deleted node
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToLL(v);

    printLL(head); // Print the original list
    cout << endl;

    // Example: Removing element 5
    head = removeElement(head, 5);
    printLL(head);

    // Additional functionality for testing:
    // head = removeIndex(head, 2);
    // head = deleteTail(head);
    // head = deleteHead(head);
    // search(head, 5);

    return 0;
}
