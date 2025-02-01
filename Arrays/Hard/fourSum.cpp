#include <bits/stdc++.h>
using namespace std;

/*
    Brute Force Approach: O(n^4) Time Complexity
    -----------------------------------------------
    Time Complexity:
      - Four nested loops result in O(n^4) iterations.
      - Each valid quadruplet is sorted (O(4log4) ≈ O(1)) and then inserted into a set.
    Space Complexity:
      - The auxiliary space is mainly used by the set that stores all unique quadruplets.
      - In the worst-case, there could be O(n^4) quadruplets, but typically this is much lower.
      - Hence, the extra space complexity is O(k), where k is the number of valid unique quadruplets.
*/
vector<vector<int>> fourSumBrute(vector<int> &arr, int target)
{
    set<vector<int>> st; // To avoid duplicate quadruplets
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
    Better Approach: O(n^3 * log(n)) Time Complexity
    ---------------------------------------------------
    Time Complexity:
      - Two fixed loops (i and j) followed by a loop over k (O(n^3)).
      - Each iteration performs a lookup in a set (O(log(n)) in worst-case).
    Space Complexity:
      - A set is used for storing numbers encountered for each pair (i, j).
      - Additionally, a global set stores the valid quadruplets.
      - The temporary set for each (i, j) pair can hold at most O(n) elements.
      - Overall extra space is O(n + k), where k is the number of valid quadruplets.
*/
vector<vector<int>> fourSumBetter(vector<int> &arr, int target)
{
    set<vector<int>> st; // To store unique quadruplets
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> prevNums; // To store numbers seen for current (i, j) pair
            for (int k = j + 1; k < n; k++)
            {
                int requiredNum = target - (arr[i] + arr[j] + arr[k]);
                if (prevNums.find(requiredNum) != prevNums.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], requiredNum};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                prevNums.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
    Optimal Approach: O(n^3) Time Complexity
    ------------------------------------------
    Time Complexity:
      - Sorting the array takes O(n log n).
      - Two nested loops for the first two numbers, then a two-pointer search for the remaining two numbers.
      - Overall time complexity is O(n^3) in the worst-case.
    Space Complexity:
      - The algorithm works in-place on the sorted array.
      - Extra space is only used for the result vector and a few loop variables.
      - Hence, the extra space complexity is O(k) where k is the number of quadruplets returned.
*/
vector<vector<int>> fourSumOptimal(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    int n = arr.size();
    if (n < 4)
        return ans; // Early exit if fewer than 4 elements
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++)
    {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            // Skip duplicates for the second element
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < target)
                    k++;
                else if (sum > target)
                    l--;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    // Skip duplicates for the third element
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    // Skip duplicates for the fourth element
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}

/*
    Main Function:
    --------------
    Tests the three approaches with various edge cases:
      1. Empty vector
      2. Fewer than 4 elements
      3. Exactly 4 elements (both matching and not matching the target)
      4. Multiple quadruplets with duplicate numbers
      5. Negative numbers and a mix of positive numbers
      6. Larger array with multiple valid quadruplets

    Each test case prints the resulting quadruplets from all three functions.
*/
int main()
{
    // Lambda function to print the vector of quadruplets
    auto printQuadruplets = [](const vector<vector<int>> &quadruplets)
    {
        if (quadruplets.empty())
        {
            cout << "No quadruplets found.\n";
            return;
        }
        for (auto &quad : quadruplets)
        {
            cout << "[ ";
            for (int num : quad)
            {
                cout << num << " ";
            }
            cout << "]\n";
        }
    };

    // Test Cases

    // 1. Edge Case: Empty vector
    {
        cout << "Test Case 1: Empty vector\n";
        vector<int> arr;
        int target = 0;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        printQuadruplets(res1);
        printQuadruplets(res2);
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 2. Edge Case: Fewer than 4 elements
    {
        cout << "Test Case 2: Fewer than 4 elements\n";
        vector<int> arr = {1, 2, 3};
        int target = 6;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        printQuadruplets(res1);
        printQuadruplets(res2);
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 3. Exactly 4 elements, valid quadruplet
    {
        cout << "Test Case 3: Exactly 4 elements, valid quadruplet\n";
        vector<int> arr = {1, 2, 3, 4};
        int target = 10;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        printQuadruplets(res1);
        printQuadruplets(res2);
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 4. Exactly 4 elements, invalid quadruplet
    {
        cout << "Test Case 4: Exactly 4 elements, invalid quadruplet\n";
        vector<int> arr = {1, 2, 3, 4};
        int target = 20;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        printQuadruplets(res1);
        printQuadruplets(res2);
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 5. Array with duplicate numbers
    {
        cout << "Test Case 5: Array with duplicates\n";
        vector<int> arr = {1, 0, -1, 0, -2, 2};
        int target = 0;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        cout << "Brute Force Results:\n";
        printQuadruplets(res1);
        cout << "Better Approach Results:\n";
        printQuadruplets(res2);
        cout << "Optimal Approach Results:\n";
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 6. Array with negative and positive numbers, multiple solutions
    {
        cout << "Test Case 6: Mixed negative and positive numbers\n";
        vector<int> arr = {2, 2, 2, 2, 2};
        int target = 8;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        cout << "Brute Force Results:\n";
        printQuadruplets(res1);
        cout << "Better Approach Results:\n";
        printQuadruplets(res2);
        cout << "Optimal Approach Results:\n";
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    // 7. Larger test case
    {
        cout << "Test Case 7: Larger array with multiple valid quadruplets\n";
        vector<int> arr = {1, 0, -1, 0, -2, 2, -1, 1};
        int target = 0;
        auto res1 = fourSumBrute(arr, target);
        auto res2 = fourSumBetter(arr, target);
        auto res3 = fourSumOptimal(arr, target);
        cout << "Brute Force Results:\n";
        printQuadruplets(res1);
        cout << "Better Approach Results:\n";
        printQuadruplets(res2);
        cout << "Optimal Approach Results:\n";
        printQuadruplets(res3);
        cout << "--------------------------\n";
    }

    return 0;
}