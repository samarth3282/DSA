#include <bits/stdc++.h>
using namespace std;

/**
 * Function: minimizeMaximumDistanceBetweenGasStationsBrute
 * --------------------------------------------------------
 * Brute force approach that iteratively places gas stations in the largest gap.
 * - Uses an array to track how many stations are placed in each segment.
 * - Finds the largest section and places a station there in each iteration.
 *
 * @param arr - Vector of existing gas station positions (sorted).
 * @param k - Number of new gas stations to add.
 * @return The minimized maximum distance after placing `k` stations.
 *
 * Time Complexity: O(K * N)
 * Space Complexity: O(N)
 */
int minimizeMaximumDistanceBetweenGasStationsBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 0; gasStations < k; gasStations++)
    {
        int maxIndex = -1, maxSection = -1;

        for (int i = 0; i < n - 1; i++)
        {
            int sectionLength = ((arr[i + 1] - arr[i]) / (howMany[i] + 1));
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, ((arr[i + 1] - arr[i]) / (howMany[i] + 1)));
    }
    return ans;
}

/**
 * Function: minimizeMaximumDistanceBetweenGasStationsBetter
 * --------------------------------------------------------
 * Uses a max-heap (priority queue) to efficiently find and split the largest section.
 * - Pushes all initial segment lengths into a max-heap.
 * - Picks the largest segment and places a station, then updates the heap.
 *
 * @param arr - Vector of existing gas station positions (sorted).
 * @param k - Number of new gas stations to add.
 * @return The minimized maximum distance after placing `k` stations.
 *
 * Time Complexity: O(K log N)
 * Space Complexity: O(N)
 */
int minimizeMaximumDistanceBetweenGasStationsBetter(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({(double)(arr[i + 1] - arr[i]), i});
    }

    for (int i = 0; i < k; i++)
    {
        auto topElement = pq.top();
        pq.pop();

        int index = topElement.second;
        howMany[index]++;

        double newPartitionSize = (double)(arr[index + 1] - arr[index]) / (howMany[index] + 1);
        pq.push({newPartitionSize, index});
    }

    return pq.top().first;
}

/**
 * Function: countNumberOfStations
 * ------------------------------
 * Counts how many gas stations are needed to ensure no segment exceeds `dist`.
 *
 * @param arr - Vector of existing gas station positions (sorted).
 * @param dist - Maximum allowed segment length.
 * @return The number of additional stations required.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int countNumberOfStations(vector<int> &arr, double dist)
{
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int numberInBetween = (arr[i + 1] - arr[i]) / dist;
        cnt += numberInBetween;
    }
    return cnt;
}

/**
 * Function: minimizeMaximumDistanceBetweenGasStationsOptimal
 * --------------------------------------------------------
 * Uses binary search to efficiently find the minimum maximum distance.
 * - Searches between `0` and the max segment length.
 * - Calls `countNumberOfStations` to check feasibility.
 * - Stops when the difference between `low` and `high` is within precision `1e-6`.
 *
 * @param arr - Vector of existing gas station positions (sorted).
 * @param k - Number of new gas stations to add.
 * @return The minimized maximum distance after placing `k` stations.
 *
 * Time Complexity: O(N log maxDist)
 * Space Complexity: O(1)
 */
double minimizeMaximumDistanceBetweenGasStationsOptimal(vector<int> &arr, int k)
{
    double low = 0, high = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        high = max((double)(arr[i + 1] - arr[i]), high);
    }

    double diff = 1e-6; // Precision for floating-point binary search
    while (high - low > diff)
    {
        double mid = low + (high - low) / 2.0;

        if (countNumberOfStations(arr, mid) > k)
        {
            low = mid; // Need to increase distance, so move right
        }
        else
        {
            high = mid; // Reduce distance, move left
        }
    }
    return high;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, // Simple case
        {1, 5, 10, 20},                  // Uneven gaps
        {2, 5, 11, 19, 25},              // Random gaps
        {1, 3, 7, 10, 15},               // Gaps increasing
        {1, 100},                        // Large gap
    };

    vector<int> stations = {9, 3, 4, 5, 10};

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << minimizeMaximumDistanceBetweenGasStationsBrute(testCases[i], stations[i]) << endl;
        cout << "Better Approach Result: " << minimizeMaximumDistanceBetweenGasStationsBetter(testCases[i], stations[i]) << endl;
        cout << "Optimal Result: " << minimizeMaximumDistanceBetweenGasStationsOptimal(testCases[i], stations[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
