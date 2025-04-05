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

bool detectALoopBrute(Node *head)
{
    unordered_set<Node *> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (st.find(temp) != st.end())
        {
            return true;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool detectALoopOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}