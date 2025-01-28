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
class Queue
{
public:
    Node *front = nullptr;
    Node *rear = nullptr;
    int currSize = 0;

    void enqueue(int data_)
    {
        Node *newNode = new Node(data_);
        if (newNode == nullptr)
        {
            cout << "Queue is full!";
        }
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
        currSize++;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!";
        }

        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            Node *toDelete = front;
            front = front->next;
            toDelete->next = nullptr;
            delete toDelete;
        }
        currSize--;
    }
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!";
            return INT_MIN;
        }
        return front->data;
    }
    int size()
    {
        return currSize;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }
};
int main()
{

    return 0;
}