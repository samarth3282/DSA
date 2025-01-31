#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int left = 0;
    int right = str.length() - 1;
    bool flag = true;
    while (left <= right)
    {
        if (str[left] == str[right])
        {
            if (str[left] == 'a' || str[left] == 'B' || str[left] == 'b' || str[left] == 'C' || str[left] == 'c' || str[left] == 'D' || str[left] == 'd' || str[left] == 'E' || str[left] == 'e' || str[left] == 'F' || str[left] == 'f' || str[left] == 'G' || str[left] == 'g' || str[left] == 'h' || str[left] == 'i' || str[left] == 'j' || str[left] == 'k' || str[left] == 'K' || str[left] == 'l' || str[left] == 'L' || str[left] == 'N' || str[left] == 'p' || str[left] == 'P' || str[left] == 'q' || str[left] == 'Q' || str[left] == 'r' || str[left] == 'R' || str[left] == 's' || str[left] == 'S' || str[left] == 't' || str[left] == 'z' || str[left] == 'Z')
            {
                flag = false;
                break;
            }
        }
        left++;
        right--;
    }
    if (flag)
    {
        cout << "TAK";
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}