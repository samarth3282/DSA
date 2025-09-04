// /*
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
    Node *reverseLL(Node *head)
    {
        Node *temp = head;
        Node *prevNode = nullptr;
        Node *nextNode = nullptr;

        while (temp)
        {
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }

        return prevNode;
    }

    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        Node *currNode = head;
        Node *prevNode = nullptr;
        while (currNode)
        {
            Node *kthNode = currNode;
            for (int i = 0; kthNode->next && i < k - 1; i++)
            {
                kthNode = kthNode->next;
            }
            // if (!kthNode)
            // {
            //     // kthNode->next =
            //     if (prevNode)
            //     {
            //         prevNode->next = currNode;
            //     }
            //     break;
            // }
            Node *nextNode = kthNode->next;
            kthNode->next = nullptr;
            Node *newHead = reverseLL(currNode);
            if (currNode == head)
            {
                head = newHead;
            }
            else
            {
                prevNode->next = newHead;
            }
            prevNode = currNode;
            currNode = nextNode;
        }
        return head;
    }
};