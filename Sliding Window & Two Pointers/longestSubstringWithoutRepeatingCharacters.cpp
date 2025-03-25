#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharactersBrute(string &str){
    int n = str.length();
    int maxLen = 0;
    for(int i= 0 ; i < str.size();i++){
        unordered_set<int> st;
        for(int j = i;j<str.length();j++){
            if(st.find(str[j])!=st.end()){
                break;
            }
            st.insert(str[j]);
        }
        maxLen = max(maxLen, (int)st.size());
    }
    return maxLen;
}
int longestSubstringWithoutRepeatingCharactersOptimal(string &str)
{
    int n = str.length();
    int left = 0;
    int right = 0;
    int maxLen = INT_MIN;
    vector<int> hashh(n, -1);
    while (right < n)
    {
        if (hashh[str[right]] != -1 && hashh[str[right]] >= left)
        {
            left = hashh[str[right]] + 1;
        }
        maxLen = max(maxLen, right - left + 1);
        hashh[str[right]] = right;
        right++;
    }
}
int main()
{

    return 0;
}