#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
Node *deleteAllOccurances(Node *head, int num)
{
    Node *prevNode = nullptr;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == num)
        {
            if(temp == head){
                head = head->next;
                head->prev = nullptr;
                temp->next = nullptr;
                delete temp;
            }
            temp->prev->next = temp->next;
            if(temp->next){

                temp->next->prev = prevNode;
            }
            temp->prev = nullptr;
            temp->next = nullptr;
            delete temp;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{

    return 0;
}