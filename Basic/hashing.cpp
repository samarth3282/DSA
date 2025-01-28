#include <bits/stdc++.h>
using namespace std;

int hashh[256];
int main()
{
    string str;
    cout << "Enter your string: ";
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        hashh[str[i]]++;
    }
    int q;
    cout << "Enter the test cases: ";
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        cout << hashh[ch] << endl;
    }

    return 0;
}