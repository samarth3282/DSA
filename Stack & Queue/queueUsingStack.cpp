#include <bits/stdc++.h>
using namespace std;
class Q
{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int data){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
    }

    void pop(){
        s1.pop();
    }

    int front(){
        s1.top();
    }

    int size(){
        return s1.size();
    }
};
int main()
{

    return 0;
}