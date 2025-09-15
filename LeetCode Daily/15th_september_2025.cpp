// 1935. Maximum Number of Words You Can Type

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        set<char> letters;
        for (int i = 0; i < brokenLetters.length(); i++)
        {
            letters.insert(brokenLetters[i]);
        }
        int ans = 0;
        vector<string> words;
        istringstream iss(text);
        string word;

        while (iss >> word)
        {
            words.push_back(word);
        }
        for (auto word : words)
        {
            bool doesContain = false;
            for (int i = 0; i < word.length(); i++)
            {
                if (letters.find(word[i]) != letters.end())
                {
                    doesContain = true;
                    break;
                }
            }
            if (doesContain)
            {
                continue;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};