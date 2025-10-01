// 3541. Find Most Frequent Vowel and Consonant

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> freq(26, 0);
        int maxVowel = 0;
        int maxConsonant = 0;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                maxVowel = max(maxVowel, freq[s[i] - 'a']);
            else
                maxConsonant = max(maxConsonant, freq[s[i] - 'a']);
        }
        return maxVowel + maxConsonant;
    }
};