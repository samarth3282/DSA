#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "(()())(())";
    queue<char> q;
    for (int i = 1; str[i]!='\0'; i++)
    {
        if (str[i-1]!=str[i])
        {
            q.push(str[i]);
        }
        
    }
    q.push(')');
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    
    return 0;
}