// 3227. Vowels Game in a String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesAliceWin(string s)
    {
        bool vowel = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
            {
                vowel = true;
                break;
            }
        }
        if (vowel)
            return true;
        else
            return false;
    }
};