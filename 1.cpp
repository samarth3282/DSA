class Solution
{
public:
    string largestSwap(string &s)
    {
        // code here
        int maxInd = -1;
        int maxNum = INT_MIN;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] - '0' >= maxNum)
            {
                maxNum = s[i] - '0';
                maxInd = i;
            }
        }
        int minInd = -1;
        int minNum = INT_MAX;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] - '0' < minNum)
            {
                minNum = s[i] - '0';
                minInd = i;
            }
        }
        // int
        // char temp = s[ind];
        // s[ind] = s[0];
        // s[0] = temp;
        // swap(s[ind],s[0]);
        return s;
    }
};