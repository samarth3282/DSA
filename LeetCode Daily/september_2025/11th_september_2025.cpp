// 2785. Sort Vowels in a String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string str)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                               'A', 'E', 'I', 'O', 'U'};
        sort(vowels.begin(), vowels.end());
        int index = 0;
        map<char, int> mpp;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                str[i] == 'U')
            {

                mpp[str[i]]++;
            }
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                str[i] == 'U')
            {
                if (mpp[vowels[index]] > 0)
                {
                    str[i] = vowels[index];
                    mpp[vowels[index]]--;
                }
                else
                {
                    while (index < vowels.size() && mpp[vowels[index]] == 0)
                        index++;
                    str[i] = vowels[index];
                    mpp[vowels[index]]--;
                }
            }
        }
        return str;
    }
};