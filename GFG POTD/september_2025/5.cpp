// /* Node is defined as
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
// */
class Solution
{
public:
    Node *segregate(Node *head)
    {
        // code here
        Node *oneHead = nullptr;
        Node *oneTail = nullptr;
        Node *zeroHead = nullptr;
        Node *zeroTail = nullptr;
        Node *twoHead = nullptr;
        Node *twoTail = nullptr;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
            {
                if (zeroHead == nullptr)
                {
                    zeroHead = temp;
                    zeroTail = temp;
                }
                else
                {
                    zeroTail->next = temp;
                    zeroTail = zeroTail->next;
                }
            }
            else if (temp->data == 1)
            {
                if (oneHead == nullptr)
                {
                    oneHead = temp;
                    oneTail = temp;
                }
                else
                {
                    oneTail->next = temp;
                    oneTail = oneTail->next;
                }
            }
            else
            {
                if (twoHead == nullptr)
                {
                    twoHead = temp;
                    twoTail = temp;
                }
                else
                {
                    twoTail->next = temp;
                    twoTail = twoTail->next;
                }
            }
            temp = temp->next;
        }
        if (oneTail)
        {
            oneTail->next = nullptr;
        }
        if (zeroTail)
        {
            zeroTail->next = nullptr;
        }
        if (twoTail)
        {
            twoTail->next = nullptr;
        }
        if (zeroTail)
        {
            zeroTail->next = oneHead ? oneHead : twoHead;
        }
        if (oneTail)
        {
            oneTail->next = twoHead ? twoHead : nullptr;
        }
        return zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
    }
};