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

int lengthOfALoopBrute(Node *head)
{
    int timer = 0;
    Node *temp = head;
    unordered_map<Node *, int> mpp;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return timer - mpp[temp];
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return -1;
}

int lengthOfALoopOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int cnt = 1;
            fast = fast->next;
            while (slow != fast)
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return -1;
}
int main()
{

    return 0;
}