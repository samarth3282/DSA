#include <bits/stdc++.h>
using namespace std;
int traversal(int start, vector<int> adjc[], int visited[]){
    visited[start] = 1;
    for(auto it : adjc[start]){
        traversal(it, adjc, visited);
    }
}
int numberOfProvinces(int n, int start, vector<int> adjc[]){
    int visited[n+1] = {0};
    int finalAns = 0;
    for (int i = start; i <= n; i++)
    {
        if (!visited[i])
        {
            finalAns++;
            traversal(i, adjc, visited);
        }
        
    }
    return finalAns;
}
int main()
{
    
    return 0;
}