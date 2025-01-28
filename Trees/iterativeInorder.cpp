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
        rightChild = leftChild = nullptr;
    }
};

void iterativeInorder(Node *root)
{
    Node *currentNode = root;
    stack<Node *> st;
    while (currentNode != nullptr || !st.empty())
    {
        while (currentNode != nullptr)
        {
            st.push(currentNode);
            currentNode = currentNode->leftChild;
        }
        currentNode = st.top();
        cout << currentNode->data << " ";
        st.pop();

        currentNode = currentNode->rightChild;
    }
}
int main()
{

    return 0;
}