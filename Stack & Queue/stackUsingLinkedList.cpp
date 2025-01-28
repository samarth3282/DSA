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
class Stack
{
public:
    Node *top = nullptr;
    int currSize = 0;
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        currSize++;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty!";
            return;
        }
        Node *topNode = top;
        top = top->next;
        topNode->next = nullptr;
        delete topNode;
        currSize--;
    }
    int peek()
    {
        if (top == nullptr)
        {
            cout << "Linked List is empty";
            return -1;
        }
        return top->data;
    }
    int size()
    {
        return currSize;
    }
};
int main()
{
    Stack stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.pop();
    printf("%d\n", stack1.peek());
    stack1.pop();
    printf("%d\n", stack1.peek());
    stack1.pop();
    printf("%d\n", stack1.peek());
    stack1.pop();
    printf("%d\n", stack1.peek());
    return 0;
}