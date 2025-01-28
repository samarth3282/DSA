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

void iterativePreorder(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<struct Node *> st;
    st.push(root);
    while (!st.empty())
    {
        struct Node *currentNode = st.top();
        st.pop();
        cout << currentNode->data << " ";
        if (currentNode->rightChild != nullptr)
        {
            st.push(currentNode->rightChild);
        }
        if (currentNode->leftChild != nullptr)
        {
            st.push(currentNode->leftChild);
        }
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->leftChild = new Node(2);
    root->leftChild->leftChild = new Node(3);
    root->leftChild->rightChild = new Node(4);
    root->rightChild = new Node(5);
    root->rightChild->leftChild = new Node(6);
    root->rightChild->rightChild = new Node(7);
    iterativePreorder(root);
    return 0;
}