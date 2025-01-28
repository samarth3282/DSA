#include <bits/stdc++.h>
using namespace std;


bool palindrome(char *str, int i, int n){
    if (i >= (n/2))
    {
        return true;
    }
    if (str[i]!=str[n-i-1])
    {
        return false;
    }
    palindrome(str, i+1, n);
    
    
}
int main()
{
    char str[21];
    cin >> str;
    cout << palindrome(str,0,strlen(str));
    return 0;
}