#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    Queue(int maxSize)
    {
        size = maxSize;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow!";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
        cout << "Element" << data << " is pushed!";
    }

    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty!";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        front = (front + 1) % size;
    }

    int front()
    {
        if (front == -1)
        {
            cout << "Queue is empty!";
            return -1;
        }
        return arr[front];
    }
    int length()
    {
        // insert your code here!
        if (front == -1)
        {
            return 0;
        }
        if (rear >= front)
        {
            return rear - front + 1;
        }
        return size - front + rear + 1;
    }
};
int main()
{

    return 0;
}