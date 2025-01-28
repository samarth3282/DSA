#include <bits/stdc++.h>
using namespace std;
void explainPairs()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second;
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << arr[0].first;
}

void explainVectors()
{
    vector<int> v;
    v.emplace_back(1);

    vector<pair<int, int>> v1;
    v1.push_back({1, 2});
    v1.emplace_back(1, 2);

    vector<int> v3(5, 100);

    vector<int> v4(5);

    vector<int> v5(v4);

    vector<int>::iterator it1 = v3.begin();
    it1++;
    cout << *it1;

    vector<int>::iterator it2 = v3.end(); // always remember to do "it--;"

    cout << v.back(); // Returns the last element

    for (vector<int>::iterator it3 = v3.begin(); it3 != v3.end(); it3++)
    {
        cout << *it3;
    }

    for (auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *it;
    }

    for (auto it : v3)
    {
        cout << it << " ";
    }

    v3.erase(v3.begin() + 1);
    v3.erase(v3.begin() + 1, v3.begin() + 3);

    v3.insert(v3.begin(), 300);
    v3.insert(v3.begin() + 1, 2, 5);

    cout << v3.size();

    v3.pop_back();

    v3.swap(v);

    cout << v.empty();
}

void explainStack()
{
    stack<int> st;
    st.push(1);        // (1)
    st.push(2);        // (2, 1)
    st.push(3);        // (3, 2, 1)
    st.push(3);        // (3, 3, 2, 13
    st.emplace(5);     // (5, 3, 3, 2, 1)
    cout << st.top();  // prints 5"**st[2] is invalid"
    st.pop();          // st Looks Like (3, 3, 2, 1)
    cout << st.top();  // 3
    cout << st.size(); // 4
    cout << st.empty();
    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue()
{

    queue<int> q;
    q.push(1); // (1)

    q.push(2); // (1, 2)

    q.emplace(4); // (1, 2, 4}

    q.back() += 5;

    cout << q.back(); // prints 9

    // Q is (1, 2, 9)

    cout << q.front(); // prints 1

    q.pop(); // (2,9)

    cout << q.front(); // prints 2

    // size swap empty same as stack
}

void explainPQ()
{
    priority_queue<int> pq;
    pq.push(5);     // (5)
    pq.push(2);     // (5,2)
    pq.push(8);     // (8, 5, 2)
    pq.emplace(10); // (18, 8, 5, 2)

    cout << pq.top(); // prints 10

    pq.pop();         // (8, 5, 2)
    cout << pq.top(); // prints 8

    // size swap empty function same as others

    // Minimum Heap

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5); // (5)

    pq.push(2); // (2,5) pq.push(8); // (2, 5, 8)

    pq.emplace(10); // (2, 5, 8, 10)

    cout << pq.top(); // prints 2
}
int main()
{

    return 0;
}