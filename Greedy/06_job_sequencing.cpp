#include <bits/stdc++.h>
using namespace std;

// 🧠 Brute-force Approach (Not efficient for large inputs)
// --------------------------------------------------------
// Try assigning each job to all possible slots from 1 to its deadline.
// For each unassigned job, scan every slot until one is free.
// Time Complexity: O(n^2)
// Space Complexity: O(n) for tracking slots
vector<int> jobSequencingBrute(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    // Step 1: Pair each job as (profit, deadline)
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {profit[i], deadline[i]};
    }

    // Step 2: Sort jobs in descending order of profit
    sort(jobs.rbegin(), jobs.rend());

    // Step 3: Find max deadline to size the slot array
    int maxDeadline = 0;
    for (auto &job : jobs)
    {
        maxDeadline = max(maxDeadline, job.second);
    }

    // Step 4: Boolean slot array to track assigned days
    vector<bool> slot(maxDeadline + 1, false);

    int totalJobs = 0, totalProfit = 0;

    // Step 5: Try assigning each job to a free slot (from job's deadline -> 1)
    for (auto &job : jobs)
    {
        int p = job.first;
        int d = job.second;

        // Scan from day d to 1 for a free slot
        for (int day = d; day >= 1; day--)
        {
            if (!slot[day])
            {
                slot[day] = true;
                totalJobs++;
                totalProfit += p;
                break;
            }
        }
    }

    return {totalJobs, totalProfit};
}

// 🧠 Optimal Approach (Same as above since Greedy is optimal here)
// --------------------------------------------------------
// The greedy strategy of picking the highest-profit job and assigning it to the latest available slot before its deadline is optimal.
// Time Complexity: O(n log n + n * maxDeadline)
//    - O(n log n) to sort jobs
//    - O(n * d) worst-case to find slots
// Space Complexity: O(d) where d = max deadline (for slot array)
vector<int> jobSequencingOptimal(vector<int> &deadline, vector<int> &profit)
{
    return jobSequencingBrute(deadline, profit); // Reuse brute as it’s already optimal
}

// 📌 Utility: Print a vector
void printVector(const vector<int> &vec)
{
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// ✅ Robust Test Cases
void testJobSequencing()
{
    {
        cout << "\nTest Case 1:\n";
        vector<int> deadline = {2, 1, 2, 1, 3};
        vector<int> profit = {100, 19, 27, 25, 15};
        vector<int> result = jobSequencingOptimal(deadline, profit);
        cout << "Expected: [3, 142] | Got: ";
        printVector(result);
    }

    {
        cout << "\nTest Case 2 (All deadlines same):\n";
        vector<int> deadline = {1, 1, 1};
        vector<int> profit = {5, 10, 15};
        vector<int> result = jobSequencingOptimal(deadline, profit);
        cout << "Expected: [1, 15] | Got: ";
        printVector(result);
    }

    {
        cout << "\nTest Case 3 (Increasing deadlines):\n";
        vector<int> deadline = {1, 2, 3, 4};
        vector<int> profit = {20, 15, 10, 5};
        vector<int> result = jobSequencingOptimal(deadline, profit);
        cout << "Expected: [4, 50] | Got: ";
        printVector(result);
    }

    {
        cout << "\nTest Case 4 (Zero jobs):\n";
        vector<int> deadline = {};
        vector<int> profit = {};
        vector<int> result = jobSequencingOptimal(deadline, profit);
        cout << "Expected: [0, 0] | Got: ";
        printVector(result);
    }

    {
        cout << "\nTest Case 5 (Multiple jobs, large deadline):\n";
        vector<int> deadline = {3, 4, 2, 1};
        vector<int> profit = {30, 40, 20, 10};
        vector<int> result = jobSequencingOptimal(deadline, profit);
        cout << "Expected: [4, 100] | Got: ";
        printVector(result);
    }
}

int main()
{
    testJobSequencing();
    return 0;
}
