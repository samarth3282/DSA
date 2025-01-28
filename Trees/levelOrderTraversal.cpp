#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;

    Node(int data_)
    {
        data = data_;
        leftChild = rightChild = nullptr;
    }
};
void levelOrdertraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *currentNode = q.front();
        q.pop();
        cout << currentNode->data << " ";
        if (currentNode->leftChild != nullptr)
        {
            q.push(currentNode->leftChild);
        }
        if (currentNode->rightChild != nullptr)
        {
            q.push(currentNode->rightChild);
        }
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->leftChild = new Node(2);
    root->rightChild = new Node(3);
    root->leftChild->leftChild = new Node(4);
    root->leftChild->rightChild = new Node(5);
    root->rightChild->leftChild = new Node(6);
    root->rightChild->rightChild = new Node(7);
    levelOrdertraversal(root);

    return 0;
}