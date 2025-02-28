#include <bits/stdc++.h>
using namespace std;

/**
 * Function: countStudents
 * -----------------------
 * Counts the number of students required to allocate books such that no student gets
 * more than `maxPages`.
 * - Adds books to a student until `maxPages` is exceeded, then assigns to a new student.
 * - Returns the number of students required for this allocation.
 *
 * @param arr - Vector containing pages in books.
 * @param maxPages - Maximum pages a student can get.
 * @return The number of students needed for this allocation.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int countStudents(vector<int> &arr, int maxPages)
{
    int studentCount = 1, currentPages = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currentPages + arr[i] <= maxPages)
        {
            currentPages += arr[i]; // Assign to current student
        }
        else
        {
            studentCount++; // Assign to a new student
            currentPages = arr[i];
        }
    }
    return studentCount;
}

/**
 * Function: allocateBooksBrute
 * ----------------------------
 * Brute-force approach to find the minimum possible maximum pages allocated to a student.
 * - Tries every possible page allocation from `max(arr)` to `sum(arr)`.
 * - Calls `countStudents` to check feasibility.
 * - Returns the minimum value where `countStudents == m`.
 *
 * @param arr - Vector containing pages in books.
 * @param m - Number of students.
 * @return The minimum possible maximum pages assigned to any student.
 *
 * Time Complexity: O((sum-max) * N)
 * Space Complexity: O(1)
 */
int allocateBooksBrute(vector<int> &arr, int m)
{
    int low = *max_element(arr.begin(), arr.end());   // Max book pages
    int high = accumulate(arr.begin(), arr.end(), 0); // Total pages sum

    for (int i = low; i <= high; i++)
    {
        if (countStudents(arr, i) == m)
            return i;
    }
    return -1;
}

/**
 * Function: allocateBooksOptimal
 * ------------------------------
 * Uses binary search to find the minimum possible maximum pages allocated to a student.
 * - Searches between `max(arr)` (minimum possible max pages) and `sum(arr)`.
 * - Calls `countStudents` to check feasibility.
 * - Returns the optimal value of max pages per student.
 *
 * @param arr - Vector containing pages in books.
 * @param m - Number of students.
 * @return The minimum possible maximum pages assigned to any student.
 *
 * Time Complexity: O(N log(sum-max))
 * Space Complexity: O(1)
 */
int allocateBooksOptimal(vector<int> &arr, int m)
{
    if (m > arr.size())
        return -1; // Not enough books for students

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countStudents(arr, mid) <= m)
        {
            high = mid - 1; // Try for a smaller max page allocation
        }
        else
        {
            low = mid + 1; // Increase allocation if not possible
        }
    }
    return low;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {12, 34, 67, 90},     // Normal case
        {10, 20, 30, 40},     // Equal distribution possible
        {15, 17, 20, 25},     // Random pages
        {5, 10, 20, 40, 80},  // Uneven book sizes
        {10, 10, 10, 10},     // All books equal
        {100, 200, 300, 400}, // Large numbers
    };

    vector<int> studentCounts = {2, 2, 2, 3, 4, 2};

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << allocateBooksBrute(testCases[i], studentCounts[i]) << endl;
        cout << "Optimal Result: " << allocateBooksOptimal(testCases[i], studentCounts[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
