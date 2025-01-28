#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data_)
    {
        data = data_;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data_, Node *next_, Node *prev_)
    {
        data = data_;
        next = next_;
        prev = prev_;
    }
};

Node *insertHead(Node *head)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    Node *newNode = new Node(data, head, nullptr);
    // newNode->prev = nullptr;
    // newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    return newNode;
}

Node *convertToDLL(vector<int> &v)
{
    if (v.empty())
    {
        return nullptr;
    }

    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i], nullptr, temp);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    cout << "NULL <--> ";
    while (temp)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Node *insertBeforeTail(Node *head)
// {
//     int data;
//     cout << "Enter the data: ";
//     cin >> data;
//     if (head == nullptr)
//     {
//         Node *newNode = new Node(data);
//         return newNode;
//     }
//     Node *temp = head;
//     while (temp->next != nullptr)
//     {
//         temp = temp->next;
//     }

//     Node *newNode = new Node(data);
//     newNode->next = temp;
//     newNode->prev = temp->prev;
//     if (temp->prev != nullptr)
//     {
//         temp->prev->next = newNode;
//     }
//     if (temp->prev == nullptr)
//     {
//         head = newNode;
//     }

//     temp->prev = newNode;
//     return head;
// }

Node *insertBeforeTail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode;
    }

    if (head->next == nullptr)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}
Node *insertNodeAtEnd(Node *head, int data_)
{
    Node *newNode = new Node(data_);
    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
// Node *insertBeforeKthElement(Node *head, int k)
// {
//     int data;
//     cout << "Enter the data: ";
//     cin >> data;
//     if (head == nullptr)
//     {
//         if (k != 1)
//         {
//             cout << "Invalid operation! List is empty and cannot find the element.\n";
//             return head;
//         }
//         Node *newNode = new Node(data);
//         return newNode;
//     }

//     if (k == 1)
//     {
//         Node *newNode = new Node(data, head, nullptr);
//         head->prev = newNode;
//         return newNode;
//     }

//     Node *temp = head;
//     int cnt = 1;
//     while (temp && cnt < k)
//     {
//         temp = temp->next;
//         cnt++;
//     }
//     if (temp != nullptr && cnt == k)
//     {
//         Node *newNode = new Node(data, temp, temp->prev);
//         temp->prev->next = newNode;
//         temp->prev = newNode;
//     }
//     else
//     {
//         cout << "Invalid operation! k is greater than the length of the list.\n";
//     }

//     return head;
// }

Node *insertBeforeKthElement(Node *head, int k, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        if (k != 1)
        {
            return nullptr;
        }
        return newNode;
    }
    if (k == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    int count = 1;
    Node *temp = head;

    while (temp != nullptr && count < k - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Out of Bounds!";
        delete newNode;
        return head;
    }

    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != nullptr)
    {

        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}
int main()
{
    // vector<int> v = {};
    // vector<int> v = {1};
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertToDLL(v);
    printDLL(head);
    head = insertBeforeKthElement(head, 2, 10);
    printDLL(head);
    return 0;
}