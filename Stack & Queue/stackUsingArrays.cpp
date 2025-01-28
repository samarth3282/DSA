#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr; // Pointer to dynamic array
    int size; // Maximum size of stack
    int top;  // Index of the top element

    Stack()
    {
        top = -1;            // Initialize top as -1 (empty stack)
        size = 1000;         // Default size of stack
        arr = new int[size]; // Dynamically allocate array
    }

    void push(int num)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = num;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return -1; // Return -1 to indicate underflow
        }
        int removedElement = arr[top];
        top--;
        return removedElement;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 to indicate empty stack
        }
        return arr[top];
    }

    int length()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack before deleting any element: " << s.getTop() << endl;
    cout << "Size of stack before deleting any element: " << s.length() << endl;

    int deletedElement = s.pop();
    cout << "The element deleted is: " << deletedElement << endl;
    cout << "Size of stack after deleting an element: " << s.length() << endl;
    cout << "Top of stack after deleting an element: " << s.getTop() << endl;

    return 0;
}
