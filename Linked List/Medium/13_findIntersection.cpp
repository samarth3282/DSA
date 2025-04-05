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
Node *findIntersection(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1)
    {
        Node *toFindNode = temp1;
        while (temp2)
        {
            if (toFindNode == temp2)
            {
                return toFindNode;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return nullptr;
}

Node *findIntersectionBetter(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    set<Node *> st;
    while (temp1)
    {
        st.insert(temp1);
        temp1 = temp1->next;
    }
    while (temp2)
    {
        if (st.find(temp2) != st.end())
        {
            return temp2;
        }
    }
    return nullptr;
}

Node *findIntersectionOptimal(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;
    while (d1 != d2)
    {
        d1 = d1 == nullptr ? head2 : d1->next;
        d2 = d2 == nullptr ? head2 : d2->next;
    }
    return d1;
}
int main()
{

    return 0;
}