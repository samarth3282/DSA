// 3408. Design Task Manager

#include <bits/stdc++.h>
using namespace std;
class TaskManager
{
public:
    struct cmp
    {
        bool operator()(const vector<int> &a, const vector<int> &b) const
        {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] > b[0];
        }
    };

    map<int, pair<int, int>> mpp;
    set<vector<int>, cmp> pq;
    TaskManager(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            mpp[tasks[i][1]] = {tasks[i][2], tasks[i][0]};
            pq.insert({tasks[i][2], tasks[i][1], tasks[i][0]});
        }
    }

    void add(int userId, int taskId, int priority)
    {
        mpp[taskId] = {priority, userId};
        pq.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority)
    {
        int prevPriority = mpp[taskId].first;
        int userId = mpp[taskId].second;
        pq.erase({prevPriority, taskId, userId});
        mpp[taskId].first = newPriority;
        pq.insert({newPriority, taskId, userId});
    }

    void rmv(int taskId)
    {
        int userId = mpp[taskId].second;
        int priority = mpp[taskId].first;
        mpp.erase(taskId);
        pq.erase({priority, taskId, userId});
    }

    int execTop()
    {
        if (!pq.empty())
        {
            vector<int> temp = *pq.begin();
            int priority = temp[0];
            int taskId = temp[1];
            int userId = temp[2];
            mpp.erase(taskId);
            pq.erase(pq.begin());
            return userId;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */