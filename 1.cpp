/*
class Node {
  public:
    int val;
    Node *next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *swapKth(Node *head, int k)
    {
        if (!head)
            return head;

        int n = 0;
        Node *curr = head;
        while (curr)
        {
            n++;
            curr = curr->next;
        }

        if (k > n)
            return head;

        Node *first = head;
        for (int i = 1; i < k; i++)
        {
            first = first->next;
        }

        Node *second = head;
        for (int i = 1; i < n - k + 1; i++)
        {
            second = second->next;
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};