#include <bits/stdc++.h>
using namespace std;
void sortByDiaginal(vector<vector<int>> &arr)
{
    int rows, cols = arr.size();
    int j = cols-1;
    while (j>=0)
    {
        vector<int> temp;
        for (int i = 0, k = j; k <= rows-1; i++, k++)
        {
            temp.push_back(arr[i][k]);
        }
        sort(temp.begin(), temp.end());
        int m = 0;
        for (int i = 0, k = j; k <= rows-1; i++, k++)
        {
            arr[i][k] = temp[m];
            m++;
        }
        
    }
    j--;
}
int main()
{

    return 0;
}