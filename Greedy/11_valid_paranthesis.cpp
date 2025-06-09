#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------
BRUTE-FORCE APPROACH (Recursive)
-------------------------------------
Try all possible replacements for '*' → '(', ')', or ''.
Check if the resulting sequence is valid.

Time Complexity: O(3^n) where n = number of '*' in the string.
Space Complexity: O(n) recursion stack depth.
*/

bool isValidParenthesisBrute(string s, int index, int balance)
{
    if (balance < 0)
        return false; // More closing brackets than opening

    if (index == s.length())
        return balance == 0;

    char currentChar = s[index];

    if (currentChar == '(')
        return isValidParenthesisBrute(s, index + 1, balance + 1);
    else if (currentChar == ')')
        return isValidParenthesisBrute(s, index + 1, balance - 1);
    else
    {
        // Try all three possibilities for '*'
        return isValidParenthesisBrute(s, index + 1, balance + 1) || // '*' → '('
               isValidParenthesisBrute(s, index + 1, balance - 1) || // '*' → ')'
               isValidParenthesisBrute(s, index + 1, balance);       // '*' → ''
    }
}

/*
-------------------------------------
BETTER APPROACH (Memoization / DP)
-------------------------------------
Use DP to avoid re-computation of overlapping subproblems.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

unordered_map<string, bool> memo;

bool isValidParenthesisMemo(string &s, int index, int balance)
{
    if (balance < 0)
        return false;

    if (index == s.length())
        return balance == 0;

    string key = to_string(index) + "_" + to_string(balance);
    if (memo.find(key) != memo.end())
        return memo[key];

    char currentChar = s[index];
    bool result = false;

    if (currentChar == '(')
        result = isValidParenthesisMemo(s, index + 1, balance + 1);
    else if (currentChar == ')')
        result = isValidParenthesisMemo(s, index + 1, balance - 1);
    else
    {
        result = isValidParenthesisMemo(s, index + 1, balance + 1) ||
                 isValidParenthesisMemo(s, index + 1, balance - 1) ||
                 isValidParenthesisMemo(s, index + 1, balance);
    }

    memo[key] = result;
    return result;
}

/*
-------------------------------------
OPTIMAL APPROACH (Greedy)
-------------------------------------
Track minimum and maximum possible open parenthesis count.

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool isValidParenthesisGreedy(string s)
{
    int minOpen = 0, maxOpen = 0;

    for (char ch : s)
    {
        if (ch == '(')
        {
            minOpen++;
            maxOpen++;
        }
        else if (ch == ')')
        {
            minOpen = max(minOpen - 1, 0);
            maxOpen--;
        }
        else
        {                                  // ch == '*'
            minOpen = max(minOpen - 1, 0); // '*' → ')'
            maxOpen++;                     // '*' → '('
        }

        if (maxOpen < 0)
            return false; // Too many ')'
    }

    return minOpen == 0;
}

/*
-------------------------------------
ROBUST TEST CASES
-------------------------------------
*/

void runTests()
{
    vector<string> testCases = {
        "(*))",         // true
        "(*()()",       // true
        "((*)",         // true
        "(*)))",        // false
        "",             // true
        "*",            // true
        ")",            // false
        "(((((*))))))", // true
        "(((******))",  // true
        "(((**))",      // false
        "*(()",         // true
        "(()*())",      // true
        "(()))",        // false
    };

    cout << "Running test cases:\n";
    for (auto &tc : testCases)
    {
        bool resultBrute = isValidParenthesisBrute(tc, 0, 0);
        memo.clear(); // Reset memo for next test case
        bool resultMemo = isValidParenthesisMemo(tc, 0, 0);
        bool resultGreedy = isValidParenthesisGreedy(tc);

        cout << "Input: \"" << tc << "\" => "
             << "Brute: " << resultBrute
             << ", Memo: " << resultMemo
             << ", Greedy: " << resultGreedy << '\n';

        assert(resultBrute == resultMemo && resultMemo == resultGreedy);
    }
    cout << "✅ All test cases passed successfully.\n";
}

int main()
{
    runTests();
    return 0;
}
