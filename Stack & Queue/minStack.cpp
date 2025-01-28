#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(int data_)
    {
        data = data_;
        next = nullptr;
    }
};
class MinStack
{
    stack<pair<int, int>> st;

    void pushMinStack(int data)
    {
        if (st.empty())
        {
            st.push({data, data});
        }
        else
        {
            if (data <= st.top().second)
            {
                st.push({data, data});
            }
            else
            {
                st.push({data, st.top().second});
            }
        }
    }

    void popMinStack()
    {
        st.pop();
    }

    int topMinStack()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().first;
    }
};
int main()
{

    return 0;
}