// Design MinMax Queue
#include <bits/stdc++.h>
using namespace std;
class SpecialQueue
{

public:
    multiset<int> ms;
    queue<int> q;
    void enqueue(int x)
    {
        q.push(x);
        ms.insert(x);
    }

    void dequeue()
    {
        int el = q.front();
        q.pop();
        ms.erase(ms.find(el));
    }

    int getFront()
    {
        return q.front();
    }

    int getMin()
    {
        return *ms.begin();
    }

    int getMax()
    {
        return *ms.rbegin();
    }
};