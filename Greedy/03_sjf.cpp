#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------
📘 PROBLEM STATEMENT:
Given an array of process burst times, compute the average waiting time if processes are scheduled using the Shortest Job First (SJF) scheduling algorithm (non-preemptive).

📌 Waiting Time:
For a process, it's the total time the process has to wait before its execution starts.

------------------------------------------------------
*/

// 🧠 Brute-Force Approach (Not applicable in this specific scenario)
// Reason: SJF needs sorting of burst times to compute waiting time optimally.
// There's no alternate naive way other than iterating and summing.

// ✅ Optimal Approach: Sort the burst times and compute cumulative wait times
int calculateAverageWaitingTimeSJF(vector<int> &burstTimes)
{
    int n = burstTimes.size();

    // Step 1: Sort the burst times (Shortest Job First Scheduling)
    sort(burstTimes.begin(), burstTimes.end());

    int totalWaitingTime = 0;
    int accumulatedBurstTime = 0;

    // Step 2: Traverse each process and calculate waiting time
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += accumulatedBurstTime;
        accumulatedBurstTime += burstTimes[i];
    }

    // Step 3: Return average waiting time
    return totalWaitingTime / n;
}

/*
------------------------------------------------------
⏱️ Time Complexity:
- Sorting: O(n log n)
- Iteration: O(n)
- Overall: O(n log n)

🧠 Space Complexity: O(1)
- No extra space other than a few variables (in-place sort on vector)

------------------------------------------------------
*/

void runTestCases()
{
    vector<vector<int>> testCases = {
        {4, 3, 7, 1, 2}, // Random case
        {10, 20, 30},    // Increasing order
        {1, 2, 3},       // Already sorted (best case)
        {5, 5, 5},       // Equal burst times
        {9},             // Single process
        {}               // Empty vector (edge case)
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case #" << i + 1 << ": ";
        if (testCases[i].empty())
        {
            cout << "No processes! Waiting time = 0" << endl;
            continue;
        }
        int avgWT = calculateAverageWaitingTimeSJF(testCases[i]);
        cout << "Average Waiting Time = " << avgWT << endl;
    }
}

int main()
{
    runTestCases();
    return 0;
}
