#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data_)
    {
        data = data;
        next = nullptr;
    }
};

Node *findStartingPointBrute(Node *head)
{
    Node *temp = head;
    set<Node *> st;

    while (temp)
    {
        if (st.find(temp) != st.end())
        {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return nullptr;
}

Node *findStartingPointOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main()
{

    return 0;
}