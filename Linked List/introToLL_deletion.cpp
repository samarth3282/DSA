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
Node *convertToLL(vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}
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
        head = new Node(data);
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

        } while ((choice != 0));
    }
    else
    {
        cout << "No elements added.\n";
    }

    return head;
}
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
void search(Node *head, int n)
{
    int cnt = 1;
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
Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
        return head;
    }
}
Node *removeIndex(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeElement(Node *head, int num)
{
    if (head == nullptr)
    {
        cout << "Linked List is empty!";
        return head;
    }
    if (head->data == num)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == num)
        {
            prev->next = prev->next->next;
            free(temp);
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
    // Node *head = createLL();
    printLL(head);
    cout << endl;
    // cout << "Enter the index of element you want to delete: ";
    // int deleteIndex;
    // cin >> deleteIndex;
    // head = removeIndex(head, deleteIndex);
    head = removeElement(head, 5);
    printLL(head);
    // cout << endl;
    // head = deleteTail(head);
    // head = deleteHead(head);
    // search(head, 5);
    return 0;
}